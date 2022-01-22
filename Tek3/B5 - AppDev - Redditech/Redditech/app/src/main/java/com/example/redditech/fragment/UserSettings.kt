package com.example.redditech.fragment

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import com.example.redditech.MainActivity
import com.example.redditech.R
import com.example.redditech.model.Prefs
import com.example.redditech.repository.Repository
import com.example.redditech.viewModels.MainViewModel
import com.example.redditech.viewModels.MainViewModelFactory


class UserSettings(private var mainView: MainActivity, private var appContainer: AppContainer) : Fragment(R.layout.user_settings) {

    private val repository = Repository()
    private val viewModelFactory = MainViewModelFactory(repository)
    private lateinit var viewModel: MainViewModel
    private lateinit var prefs: Prefs

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        val doneButton: Button = view.findViewById(R.id.done)
        viewModel = ViewModelProvider(this, viewModelFactory).get(MainViewModel::class.java)
        doneButton.setOnClickListener {
            viewModel.patchPrefs("Bearer ${mainView.accessToken}", prefs)
            appContainer.goUser()
        }
        getUserSettings(view)
        val searchOver18: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.search_over_18)
        val publicVotes: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.public_votes)
        val allowClickTracking: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.allow_clicktracking)
        val showGoldExpiration: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.show_gold_expiration)
        val showLocationBasedRecommendations: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.show_location_based_recommendations)
        val markMessagesRead: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.mark_messages_read)

        searchOver18.setOnCheckedChangeListener { _, _ ->
            prefs.search_include_over_18 = searchOver18.isChecked
        }

        publicVotes.setOnCheckedChangeListener { _, _ ->
            prefs.public_votes = publicVotes.isChecked
        }

        allowClickTracking.setOnCheckedChangeListener { _, _ ->
            prefs.allow_clicktracking = allowClickTracking.isChecked
        }

        showGoldExpiration.setOnCheckedChangeListener { _, _ ->
            prefs.show_gold_expiration = showGoldExpiration.isChecked
        }

        showLocationBasedRecommendations.setOnCheckedChangeListener { _, _ ->
            prefs.show_location_based_recommendations = showLocationBasedRecommendations.isChecked
        }

        markMessagesRead.setOnCheckedChangeListener { _, _ ->
            prefs.mark_messages_read = markMessagesRead.isChecked
        }
    }

    private fun getUserSettings(view: View) {
        viewModel.getPrefs("Bearer ${mainView.accessToken}")
        viewModel.prefs.observe(viewLifecycleOwner, { response ->
            if (response.isSuccessful) {
                Log.d("MyResponse", response.body().toString())
                prefs = response.body()!!
                displayPrefs(view)
            } else {
                Log.d("Response", "There is an error.")
                Log.d("Response", response.code().toString())
                Log.d("Response", response.errorBody().toString())
            }
        })
    }

    private fun displayPrefs(view: View) {
        val searchOver18: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.search_over_18)
        val publicVotes: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.public_votes)
        val allowClickTracking: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.allow_clicktracking)
        val showGoldExpiration: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.show_gold_expiration)
        val showLocationBasedRecommendations: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.show_location_based_recommendations)
        val markMessagesRead: androidx.appcompat.widget.SwitchCompat = view.findViewById(R.id.mark_messages_read)

        searchOver18.isChecked = prefs.search_include_over_18
        publicVotes.isChecked = prefs.public_votes
        allowClickTracking.isChecked = prefs.allow_clicktracking
        showGoldExpiration.isChecked = prefs.show_gold_expiration
        showLocationBasedRecommendations.isChecked = prefs.show_location_based_recommendations
        markMessagesRead.isChecked = prefs.mark_messages_read

    }
}