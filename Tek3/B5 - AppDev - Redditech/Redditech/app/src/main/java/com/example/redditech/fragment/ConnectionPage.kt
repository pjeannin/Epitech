package com.example.redditech.fragment

import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.fragment.app.Fragment
import com.example.redditech.MainActivity
import com.example.redditech.R


class ConnectionPage(private var mainView: MainActivity) : Fragment(R.layout.connection_page) {
    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        val signInButton: Button = view.findViewById(R.id.signIn)

        signInButton.setOnClickListener {
            mainView.startSignIn()
        }
    }
}