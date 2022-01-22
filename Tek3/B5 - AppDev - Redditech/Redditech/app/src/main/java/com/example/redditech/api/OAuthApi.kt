package com.example.redditech.api

import com.example.redditech.model.*
import retrofit2.Response
import retrofit2.http.*

interface OAuthApi {
    @GET("hot")
    suspend fun getHotPost(
        @Header("Authorization") accessToken: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("hot")
    suspend fun getAfterHotPost(
        @Header("Authorization") accessToken: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("new")
    suspend fun getNewPost(
        @Header("Authorization") accessToken: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("new")
    suspend fun getAfterNewPost(
        @Header("Authorization") accessToken: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>


    @GET("top")
    suspend fun getTopPost(
        @Header("Authorization") accessToken: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("top")
    suspend fun getAfterTopPost(
        @Header("Authorization") accessToken: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>


    @GET("api/v1/me")
    suspend fun getMe(
        @Header("Authorization") accessToken: String,
        @Query("raw_json") value: Int = 1
    ): Response<Me>

    @GET("api/v1/me/prefs")
    suspend fun getMePrefs(
        @Header("Authorization") accessToken: String,
        @Query("raw_json") value: Int = 1
    ): Response<Prefs>

    @GET("subreddits/search")
    suspend fun getSubredditSearch(
        @Header("Authorization") accessToken: String,
        @Query("q") query: String,
        @Query("limit") limit: Int = 100,
        @Query("raw_json") value: Int = 1
    ): Response<SubredditSearch>

    @PATCH("api/v1/me/prefs")
    suspend fun patchMePrefs(
        @Header("Authorization") accessToken: String,
        @Body prefs: Prefs,
        @Query("raw_json") value: Int = 1
    ): Response<Prefs>

    @GET("user/{username}/new")
    suspend fun getUserNewPost(
        @Header("Authorization") accessToken: String,
        @Path("username") username: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("user/{username}/new")
    suspend fun getAfterUserNewPost(
        @Header("Authorization") accessToken: String,
        @Path("username") username: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/about")
    suspend fun getSubredditDetails(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("raw_json") value: Int = 1
    ): Response<ChildrenData>

    @GET("{sub_name}/new")
    suspend fun getSubredditPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/new")
    suspend fun getSubredditAfterPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/hot")
    suspend fun getSubredditHotPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/hot")
    suspend fun getSubredditHotAfterPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/top")
    suspend fun getSubredditTopPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @GET("{sub_name}/top")
    suspend fun getSubredditTopAfterPosts(
        @Header("Authorization") accessToken: String,
        @Path("sub_name") sub_name: String,
        @Query("after") after: String,
        @Query("raw_json") value: Int = 1,
        @Query("sr_detail") detail: String = "sr_detail"
    ): Response<HomePostList>

    @POST("api/subscribe")
    suspend fun postSubscribe(
        @Header("Authorization") accessToken: String,
        @Query("action") action: String,
        @Query("sr_name") name: String,
    )
}