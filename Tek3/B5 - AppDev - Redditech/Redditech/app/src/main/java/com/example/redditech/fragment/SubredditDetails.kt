package com.example.redditech.fragment

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.ProgressBar
import android.widget.TextView
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.MainActivity
import com.example.redditech.R
import com.example.redditech.model.ChildrenData
import com.example.redditech.model.HomePostList
import com.example.redditech.recyclerViewAdapter.PostRecyclerAdapter
import com.example.redditech.repository.Repository
import com.example.redditech.viewModels.MainViewModel
import com.example.redditech.viewModels.MainViewModelFactory
import com.squareup.picasso.Picasso
import retrofit2.Response

class SubredditDetails(private var subredditName: String, private var mainView: MainActivity) : Fragment(R.layout.subreddit_details) {

    private val repository = Repository()
    private val viewModelFactory = MainViewModelFactory(repository)
    private lateinit var viewModel: MainViewModel
    private lateinit var details: ChildrenData
    private var after: String = ""
    private var layoutManager: RecyclerView.LayoutManager? = null
    private var adapterPost: RecyclerView.Adapter<PostRecyclerAdapter.ViewHolder>? = null
    private var isLoading = true
    private var currentFilter = "hot"

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        layoutManager = LinearLayoutManager(activity)
        val recyclerView: RecyclerView = view.findViewById(R.id.recyclerView)
        recyclerView.layoutManager = layoutManager

        val subButton: Button = view.findViewById(R.id.subscribe)
        subButton.setOnClickListener {
            viewModel.postSubscribe("Bearer ${mainView.accessToken}", (if (details.data.user_is_subscriber) "unsub" else "sub"), subredditName)
            details.data.user_is_subscriber = !details.data.user_is_subscriber
            subButton.text = if (details.data.user_is_subscriber) "Unsubscribe" else "Subscribe"
        }

        val newButton = view.findViewById<Button>(R.id.new_Filter)
        newButton.setOnClickListener {
            currentFilter = "new"
            updateFilterBar(view)
            getNewPost(view)
        }

        val hotButton = view.findViewById<Button>(R.id.hot_Filter)
        hotButton.setOnClickListener {
            currentFilter = "hot"
            updateFilterBar(view)
            getHotPost(view)
        }
        val topButton = view.findViewById<Button>(R.id.Top_Filter)
        topButton.setOnClickListener {
            currentFilter = "top"
            updateFilterBar(view)
            getTopPost(view)
        }

        adapterPost = context?.let { PostRecyclerAdapter(it) }
        recyclerView.adapter = adapterPost
        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)
        val name: TextView = view.findViewById(R.id.subredditName)
        name.text = subredditName
        recyclerView.addOnScrollListener(object: RecyclerView.OnScrollListener() {
            override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
                val visibleItemCount = (layoutManager as LinearLayoutManager).childCount
                val pastVisibleItem = (layoutManager as LinearLayoutManager).findFirstCompletelyVisibleItemPosition()
                val total = (adapterPost as PostRecyclerAdapter).itemCount
                if (!isLoading && (visibleItemCount + pastVisibleItem) >= total) {
                    getNextPage(view)
                }
                super.onScrolled(recyclerView, dx, dy)
            }
        })
        viewModel.getSubredditDetails("Bearer ${mainView.accessToken}", subredditName)
        viewModel.subredditDetails.observe(viewLifecycleOwner, { response ->
            if (response.isSuccessful) {
                Log.d("MyResponse", response.body().toString())
                details = response.body()!!
                setDetails(view)
                getHotPost(view)
                Log.d("Sub", details.data.user_is_subscriber.toString())
                subButton.text = if (details.data.user_is_subscriber) "Unsubscribe" else "Subscribe"
            } else {
                Log.d("Response", "There is an error.")
                Log.d("Response", response.code().toString())
                Log.d("Response", response.errorBody().toString())
            }
        })
    }

    private fun setDetails(view: View) {
        val description: TextView = view.findViewById(R.id.aboutContent)
        val profilePicture: ImageView = view.findViewById(R.id.profilePicture)
        val headerPicture: ImageView = view.findViewById(R.id.headerImage)
        val community: TextView = view.findViewById(R.id.comminuty)
        description.text = if (details.data.public_description != "") details.data.public_description else "User has no description"
        community.text = resources.getString(R.string.subscriber, details.data.subscribers)
        if (details.data.community_icon != "" || details.data.icon_img != "")
            Picasso.get().load(if (details.data.community_icon == "") details.data.icon_img else details.data.community_icon).into(profilePicture)
        if (details.data.banner_img != "" || details.data.banner_background_image != "") {
            Picasso.get()
                .load(if (details.data.banner_img != "") details.data.banner_img else details.data.banner_background_image)
                .into(headerPicture)
            /*if ((if (details.data.banner_img != "") details.data.banner_img else details.data.banner_background_image) == details.data.banner_background_image) {
                val params: ViewGroup.LayoutParams = headerPicture.layoutParams
                headerPicture.layoutParams = params
            }*/
        }
    }

    private fun updateFilterBar(view: View) {
        val newLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id.wrapper1)
        val hotLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id.wrapper12)
        val topLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id.wrapper123)
        newLayout.setBackgroundResource(R.drawable.rounded_lightblue_background)
        topLayout.setBackgroundResource(R.drawable.rounded_lightblue_background)
        hotLayout.setBackgroundResource(R.drawable.rounded_lightblue_background)
        when(currentFilter) {
            "hot" -> hotLayout.setBackgroundResource(R.drawable.rounded_purple_background)
            "top" -> topLayout.setBackgroundResource(R.drawable.rounded_purple_background)
            else -> newLayout.setBackgroundResource(R.drawable.rounded_purple_background)
        }
    }

    private fun getHotPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            progressBar.visibility = View.VISIBLE
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            viewModel.getSubredditHotPost("Bearer ${mainView.accessToken}", subredditName)
            viewModel.subredditHotPosts.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
        }
    }

    private fun getNewPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            progressBar.visibility = View.VISIBLE
            viewModel.getSubredditPost("Bearer ${mainView.accessToken}", subredditName)
            viewModel.subredditPosts.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
        }
    }

    private fun getTopPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            progressBar.visibility = View.VISIBLE
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            viewModel.getSubredditTopPost("Bearer ${mainView.accessToken}", subredditName)
            viewModel.subredditTopPosts.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
        }
    }

    private fun getObserver(response: Response<HomePostList>, view: View) {
        val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
        if (response.isSuccessful) {
            Log.d("Response", response.body().toString())
            after = response.body()?.data?.after ?: ""
            response.body()?.data?.let { it1 ->
                (adapterPost as PostRecyclerAdapter).setData(
                    it1.children, after)
            }
        } else {
            Log.d("Response", "There is an error.")
            Log.d("Response", response.code().toString())
            Log.d("Response", response.errorBody().toString())
        }
        isLoading = false
        progressBar.visibility = View.GONE
    }

    private fun afterObserver(response: Response<HomePostList>, view: View) {
        val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
        if (response.isSuccessful) {
            Log.d("Response", response.body().toString())
            after = response.body()?.data?.after ?: ""
            response.body()?.data?.let { it1 ->
                (adapterPost as PostRecyclerAdapter).addData(
                    it1.children,
                    after
                )
            }
        } else {
            Log.d("Response", "There is an error.")
            Log.d("Response", response.code().toString())
            Log.d("Response", response.errorBody().toString())
        }
        isLoading = false
        progressBar.visibility = View.GONE
    }

    private fun getNextPage(view: View) {
        if (isLoading)
            return
        isLoading = true
        val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
        progressBar.visibility = View.VISIBLE
        Log.d("Response", "Call next page")
        when (currentFilter) {
            "hot" -> {
                viewModel.getSubredditHotAfterPost("Bearer ${mainView.accessToken}", subredditName, after)
                viewModel.subredditHotAfterPosts.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
            "new" -> {
                viewModel.getSubredditAfterPost("Bearer ${mainView.accessToken}", subredditName, after)
                viewModel.subredditAfterPosts.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
            else -> {
                viewModel.getSubredditTopAfterPost("Bearer ${mainView.accessToken}", subredditName, after)
                viewModel.subredditTopAfterPosts.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
        }

    }
}