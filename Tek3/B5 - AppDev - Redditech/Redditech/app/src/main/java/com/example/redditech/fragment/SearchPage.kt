package com.example.redditech.fragment

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.ImageButton
import androidx.core.widget.doAfterTextChanged
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.MainActivity
import com.example.redditech.R
import com.example.redditech.recyclerViewAdapter.SubRecyclerAdapter
import com.example.redditech.repository.Repository
import com.example.redditech.viewModels.MainViewModel
import com.example.redditech.viewModels.MainViewModelFactory

class SearchPage(private var mainView: MainActivity, private var appContainer: AppContainer) : Fragment(R.layout.search_page) {

    private var layoutManager: RecyclerView.LayoutManager? = null
    private var adapterSub: RecyclerView.Adapter<SubRecyclerAdapter.ViewHolder>? = null
    private val repository = Repository()
    private val viewModelFactory = MainViewModelFactory(repository)
    private lateinit var viewModel: MainViewModel

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)
        val recyclerView: RecyclerView = view.findViewById(R.id.recyclerView)
        val crossButton: ImageButton = view.findViewById(R.id.crossButton)
        val textEdit = view.findViewById<com.google.android.material.textfield.TextInputEditText>(R.id.textInput)

        crossButton.setOnClickListener {
            textEdit.setText("")
        }

        layoutManager = LinearLayoutManager(activity)
        recyclerView.layoutManager = layoutManager

        adapterSub = context?.let { SubRecyclerAdapter(appContainer, it) }
        recyclerView.adapter = adapterSub

        textEdit.doAfterTextChanged {
            if (it.toString() != "") {
                viewModel.getSubredditSearch("Bearer ${mainView.accessToken}", it.toString())
                viewModel.subredditSearch.observe(viewLifecycleOwner, { response ->
                    if (response.isSuccessful) {
                        Log.d("MyResponse", response.body().toString())
                        response.body()?.data?.let { it1 ->
                            (adapterSub as SubRecyclerAdapter).setData(
                                it1.children
                            )
                        }
                    } else {
                        Log.d("Response", "There is an error.")
                        Log.d("Response", response.code().toString())
                        Log.d("Response", response.errorBody().toString())
                    }
                })
            } else {
                (adapterSub as SubRecyclerAdapter).setData(listOf())
            }
        }
    }
}