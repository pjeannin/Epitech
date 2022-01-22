package com.example.redditech.api

import com.example.redditech.util.Constants.Companion.OAUTH_URL
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

object RetrofitOauthInstance {
    private val retrofit by lazy {
        Retrofit.Builder()
            .baseUrl(OAUTH_URL)
            .addConverterFactory(GsonConverterFactory.create())
            .build()
    }

    val api: OAuthApi by lazy {
        retrofit.create(OAuthApi::class.java)
    }
}