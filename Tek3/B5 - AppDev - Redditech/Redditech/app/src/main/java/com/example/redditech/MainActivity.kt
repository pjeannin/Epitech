package com.example.redditech

import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import java.util.Base64
import android.util.Log
import com.example.redditech.databinding.ActivityMainBinding
import com.example.redditech.fragment.AppContainer
import com.example.redditech.fragment.ConnectionPage

class MainActivity : AppCompatActivity() {

    var accessToken: String = ""

    private var isConnected : Boolean = false
    private lateinit var binding: ActivityMainBinding

    private val authUrl = "https://www.reddit.com/api/v1/authorize.compact?client_id=%s&response_type=code&state=%s&redirect_uri=%s&duration=permanent&scope=*"
    private val clientId = "W752HSGWq0KX0H-1IzBGqw"
    private val redirectUri = "http://localhost"
    private val state = "achetez_des_AirPods"

    private lateinit var encoded: String
    private var code: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(R.layout.activity_main)
        val fragmentManager = supportFragmentManager
        val fragmentTransaction = fragmentManager.beginTransaction()
        if (isConnected) {
            fragmentTransaction.replace(R.id.FragmentContainer, AppContainer(this, code, encoded))
        } else {
            fragmentTransaction.replace(R.id.FragmentContainer, ConnectionPage(this))
        }
        fragmentTransaction.commit()
    }

    override fun onResume() {
        super.onResume()
        if (!isConnected && intent != null && intent.action == Intent.ACTION_VIEW) {
            val uri = intent.data
            if (uri!!.getQueryParameter("error") != null) {
                val error = uri.getQueryParameter("error")
                Log.e("Redditech", "An error has occurred : $error")
            } else {
                val state = uri.getQueryParameter("state")
                if (state == this.state) {
                    code = uri.getQueryParameter("code")
                    if (code != null) {
                        val beforeEncode = "$clientId:$code"
                        encoded = Base64.getEncoder().encodeToString(beforeEncode.toByteArray())
                        Log.d("Response", encoded)
                        changeFragment()
                    }
                }
            }
        }
    }

    private fun changeFragment() {
        isConnected = true
        val fragmentManager = supportFragmentManager
        val fragmentTransaction = fragmentManager.beginTransaction()
        fragmentTransaction.replace(R.id.FragmentContainer, AppContainer(this, code, encoded))
        fragmentTransaction.commit()
    }

    fun startSignIn() {
        val intent = Intent(Intent.ACTION_VIEW, Uri.parse(String.format(authUrl, clientId, state, redirectUri)))
        startActivity(intent)
    }
}