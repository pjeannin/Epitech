package com.example.redditech.fragment

import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.fragment.app.Fragment
import com.example.redditech.MainActivity
import com.example.redditech.R

class AppContainer(private var mainView: MainActivity, private var code: String?, var encoded: String) : Fragment(R.layout.app_containter) {
    private var currentPage: String = "HomePage"
    private lateinit var currentDetails: String
    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        updateFragment()

        val searchButton = view.findViewById<Button>(R.id.Search)
        searchButton.setOnClickListener {
            val homeLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id._wrapper1)
            val searchLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper12
            )
            val profileLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper123
            )
            searchLayout.setBackgroundResource(R.drawable.rounded_lightbluesmall_background)
            homeLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            profileLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            currentPage = "SearchPage"
            updateFragment()
        }

        val homeButton = view.findViewById<Button>(R.id.Home)
        homeButton.setOnClickListener {
            val homeLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id._wrapper1)
            val searchLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper12
            )
            val profileLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper123
            )
            searchLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            homeLayout.setBackgroundResource(R.drawable.rounded_lightbluesmall_background)
            profileLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            currentPage = "HomePage"
            updateFragment()
        }
        val profileButton = view.findViewById<Button>(R.id.profile)
        profileButton.setOnClickListener {
            val homeLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(R.id._wrapper1)
            val searchLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper12
            )
            val profileLayout = view.findViewById<androidx.constraintlayout.widget.ConstraintLayout>(
                R.id._wrapper123
            )
            searchLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            homeLayout.setBackgroundResource(R.drawable.rounded_purplebig_background)
            profileLayout.setBackgroundResource(R.drawable.rounded_lightbluesmall_background)
            currentPage = "ProfilePage"
            updateFragment()
        }
    }

    private fun updateFragment() {
        val fragmentManager = childFragmentManager
        val fragmentTransaction = fragmentManager.beginTransaction()
        when (currentPage) {
            "HomePage" -> {
                fragmentTransaction.replace(R.id.FragmentAppContainer, HomePage(mainView, code, encoded))
            }
            "SearchPage" -> {
                fragmentTransaction.replace(R.id.FragmentAppContainer, SearchPage(mainView, this))
            }
            "ProfilePage" -> {
                fragmentTransaction.replace(R.id.FragmentAppContainer, ProfilePage(mainView, this))
            }
            "SubredditDetails" -> {
                fragmentTransaction.replace(R.id.FragmentAppContainer, SubredditDetails(currentDetails, mainView))
            }
            "Settings" -> {
                fragmentTransaction.replace(R.id.FragmentAppContainer, UserSettings(mainView, this))
            }
        }
        fragmentTransaction.commit()
    }

    fun goSubDetails(subredditName: String) {
        currentPage = "SubredditDetails"
        currentDetails = subredditName
        updateFragment()
    }

    fun goSettingsPage() {
        currentPage = "Settings"
        val navBarLayout: androidx.constraintlayout.widget.ConstraintLayout? = view?.findViewById(R.id.navBar)
        if (navBarLayout != null) {
            navBarLayout.visibility = View.GONE
        }
        updateFragment()
    }

    fun goUser() {
        currentPage = "ProfilePage"
        val navBarLayout: androidx.constraintlayout.widget.ConstraintLayout? = view?.findViewById(R.id.navBar)
        if (navBarLayout != null) {
            navBarLayout.visibility = View.VISIBLE
        }
        updateFragment()
    }
}