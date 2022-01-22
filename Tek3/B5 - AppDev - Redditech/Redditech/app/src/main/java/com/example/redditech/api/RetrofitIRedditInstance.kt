package com.example.redditech.api

import com.example.redditech.util.Constants.Companion.REDDIT_URL
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

object RetrofitIRedditInstance {
    private val retrofit by lazy {
        Retrofit.Builder()
            .baseUrl(REDDIT_URL)
            .addConverterFactory(GsonConverterFactory.create())
            .build()
    }
    val api: RedditApi by lazy {
        retrofit.create(RedditApi::class.java)
    }
}