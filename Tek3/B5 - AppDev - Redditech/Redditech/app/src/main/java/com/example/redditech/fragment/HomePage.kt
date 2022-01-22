package com.example.redditech.fragment

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.ProgressBar
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.*
import com.example.redditech.model.HomePostList
import com.example.redditech.recyclerViewAdapter.PostRecyclerAdapter
import com.example.redditech.repository.Repository
import com.example.redditech.viewModels.MainViewModel
import com.example.redditech.viewModels.MainViewModelFactory
import retrofit2.Response

class HomePage(private var mainView: MainActivity, private var code: String?, private var encoded: String) : Fragment(R.layout.home_page)  {

    private var currentFilter: String = "hot"
    private lateinit var after: String
    private val repository = Repository()
    private val viewModelFactory = MainViewModelFactory(repository)
    private lateinit var viewModel: MainViewModel

    private var isLoading = true

    private var layoutManager: RecyclerView.LayoutManager? = null
    private var adapterPost: RecyclerView.Adapter<PostRecyclerAdapter.ViewHolder>? = null

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        val newButton = view.findViewById<Button>(R.id.new_Filter)
        val recyclerView: RecyclerView = view.findViewById(R.id.recyclerView)
        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)

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
                    getNextPage(view)
                }
                super.onScrolled(recyclerView, dx, dy)
            }
        })

        val repository = Repository()
        val viewModelFactory = MainViewModelFactory(repository)
        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)
        val tmpCode = code
        if (tmpCode != null) {
            viewModel.getAccessToken("Basic $encoded", tmpCode)
            viewModel.accessToken.observe(viewLifecycleOwner, { response ->
                if (response.isSuccessful) {
                    Log.d("Response", response.body().toString())
                    mainView.accessToken = response.body()?.access_token ?: ""
                    getHotPost(view)
                } else {
                    Log.d("Response", "There is an error.")
                    Log.d("Response", response.code().toString())
                    Log.d("Response", response.errorBody().toString())
                }
            })
        }

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
    }

    override fun onResume() {
        super.onResume()
        view?.let { getHotPost(it) }
    }

    private fun getHotPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            progressBar.visibility = View.VISIBLE
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            viewModel.getHotPost("Bearer ${mainView.accessToken}")
            viewModel.hotPost.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
        }
    }

    private fun getNewPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            progressBar.visibility = View.VISIBLE
            viewModel.getNewPost("Bearer ${mainView.accessToken}")
            viewModel.newPost.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
        }
    }

    private fun getTopPost(view: View) {
        if (mainView.accessToken != "") {
            isLoading = true
            val progressBar: ProgressBar = view.findViewById(R.id.progressBar)
            progressBar.visibility = View.VISIBLE
            (adapterPost as PostRecyclerAdapter).setData(emptyList(), "")
            viewModel.getTopPost("Bearer ${mainView.accessToken}")
            viewModel.topPost.observe(viewLifecycleOwner, { response -> getObserver(response, view) })
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
                viewModel.getAfterHotPost("Bearer ${mainView.accessToken}", after)
                viewModel.afterHotPost.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
            "new" -> {
                viewModel.getAfterNewPost("Bearer ${mainView.accessToken}", after)
                viewModel.afterNewPost.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
            else -> {
                viewModel.getAfterTopPost("Bearer ${mainView.accessToken}", after)
                viewModel.afterTopPost.observe(viewLifecycleOwner, { response -> afterObserver(response, view) })
            }
        }

    }
}