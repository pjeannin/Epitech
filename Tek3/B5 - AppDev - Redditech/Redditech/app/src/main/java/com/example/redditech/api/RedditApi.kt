package com.example.redditech.api

import com.example.redditech.model.AccessToken
import retrofit2.Response
import retrofit2.http.POST
import retrofit2.http.Header
import retrofit2.http.Query

interface RedditApi {
    @POST("api/v1/access_token")
    suspend fun getAccesToken(
        @Header("Authorization") authorization: String,
        @Query("code") code: String,
        @Query("redirect_uri") uri: String = "http://localhost",
        @Query("grant_type") grant_type: String = "authorization_code"
    ): Response<AccessToken>
}