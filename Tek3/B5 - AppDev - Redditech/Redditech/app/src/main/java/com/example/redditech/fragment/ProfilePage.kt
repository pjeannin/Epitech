package com.example.redditech.fragment

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.ImageButton
import android.widget.ImageView
import android.widget.ProgressBar
import android.widget.TextView
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.MainActivity
import com.example.redditech.R
import com.example.redditech.model.Me
import com.example.redditech.recyclerViewAdapter.PostRecyclerAdapter
import com.example.redditech.repository.Repository
import com.example.redditech.viewModels.MainViewModel
import com.example.redditech.viewModels.MainViewModelFactory
import com.squareup.picasso.Picasso

class ProfilePage(private var mainView: MainActivity, private var appContainer: AppContainer) : Fragment(R.layout.profile_page) {


    private val repository = Repository()
    private val viewModelFactory = MainViewModelFactory(repository)
    private lateinit var viewModel: MainViewModel
    private lateinit var me: Me
    private var layoutManager: RecyclerView.LayoutManager? = null
    private var adapterPost: RecyclerView.Adapter<PostRecyclerAdapter.ViewHolder>? = null
    private var after: String = ""
    private var isLoading: Boolean = true

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        val recyclerView: RecyclerView = view.findViewById(R.id.recyclerView)

        layoutManager = LinearLayoutManager(activity)
        recyclerView.layoutManager = layoutManager

        adapterPost = context?.let { PostRecyclerAdapter(it) }
        recyclerView.adapter = adapterPost

        recyclerView.addOnScrollListener(object: RecyclerView.OnScrollListener() {
            override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
                val visibleItemCount = (layoutManager as LinearLayoutManager).childCount
                val pastVisibleItem = (layoutManager as LinearLayoutManager).findFirstCompletelyVisibleItemPosition()
                val total = (adapterPost as PostRecyclerAdapter).itemCount
                if (!isLoading && (visibleItemCount + pastVisibleItem) >= total) {
                    getAfterUserPost(view)
                }
                super.onScrolled(recyclerView, dx, dy)
            }
        })

        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)
        getUserInfos(view)

        val settingsButton: ImageButton = view.findViewById(R.id.settingsButton)
        settingsButton.setOnClickListener {
            appContainer.goSettingsPage()
        }
    }

    private fun getUserInfos(view: View) {
        viewModel.getMe("Bearer ${mainView.accessToken}")
        viewModel.me.observe(viewLifecycleOwner, { response ->
            if (response.isSuccessful) {
                Log.d("MyResponse", response.body().toString())
                me = response.body() as Me
                setData(view)
                getUserPost(view)
            } else {
                Log.d("Response", "There is an error.")
                Log.d("Response", response.code().toString())
                Log.d("Response", response.errorBody().toString())
            }
        })
    }

    private fun getUserPost(view: View) {
        val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
        viewModel.getUserNewPost("Bearer ${mainView.accessToken}", me.name)
        viewModel.userNewPost.observe(viewLifecycleOwner, { response ->
            if (response.isSuccessful) {
                after = response.body()?.data?.after ?: ""
                Log.d("MyResponse", response.body().toString())
                response.body()?.data?.let { it1 ->
                    (adapterPost as PostRecyclerAdapter).setData(
                        it1.children, after
                    )
                }
                isLoading = false
                progressBar.visibility = View.GONE
            } else {
                Log.d("Response", "There is an error.")
                Log.d("Response", response.code().toString())
                Log.d("Response", response.errorBody().toString())
            }
        })
    }

    private fun getAfterUserPost(view: View) {
        val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
        Log.d("Update", "In after user post")
        if (after != "") {
            isLoading = true
            progressBar.visibility = View.VISIBLE
            viewModel.getUseAfterNewPost("Bearer ${mainView.accessToken}", me.name, after)
            viewModel.userAfterNewPost.observe(viewLifecycleOwner, { response ->
                if (response.isSuccessful) {
                    after = response.body()?.data?.after ?: ""
                    Log.d("MyResponse", response.body().toString())
                    response.body()?.data?.let { it1 ->
                        (adapterPost as PostRecyclerAdapter).addData(
                            it1.children, after
                        )
                        isLoading = false
                        progressBar.visibility = View.GONE
                    }
                } else {
                    Log.d("Response", "There is an error.")
                    Log.d("Response", response.code().toString())
                    Log.d("Response", response.errorBody().toString())
                }
            })
        }
    }

    private fun setData(view: View) {
        val username: TextView = view.findViewById(R.id.username)
        val description: TextView = view.findViewById(R.id.aboutMeContent)
        val profilePicture: ImageView = view.findViewById(R.id.profilePicture)
        val headerPicture: ImageView = view.findViewById(R.id.headerImage)
        username.text = me.subreddit.display_name_prefixed
        description.text = if (me.subreddit.public_description != "") me.subreddit.public_description else "User has no description"
        Log.d("Image", me.subreddit.icon_img)
        Log.d("Image", me.subreddit.banner_img)
        Picasso.get().load(me.subreddit.icon_img).into(profilePicture)
        Picasso.get().load(me.subreddit.banner_img).into(headerPicture)
    }
}