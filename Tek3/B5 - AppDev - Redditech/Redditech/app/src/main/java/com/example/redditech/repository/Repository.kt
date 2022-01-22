package com.example.redditech.repository

import com.example.redditech.api.RetrofitIRedditInstance
import com.example.redditech.api.RetrofitOauthInstance
import com.example.redditech.model.*
import retrofit2.Response

class Repository {
    suspend fun getAccessToken(authorisation: String, code: String): Response<AccessToken> {
        return RetrofitIRedditInstance.api.getAccesToken(authorisation, code)
    }

    suspend fun getHotPost(authorisation: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getHotPost(authorisation)
    }

    suspend fun getAfterHotPost(authorisation: String, after: String): Response<HomePostList> {
    return RetrofitOauthInstance.api.getAfterHotPost(authorisation, after)
    }

    suspend fun getNewPost(authorisation: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getNewPost(authorisation)
    }

    suspend fun getAfterNewPost(authorisation: String, after: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getAfterNewPost(authorisation, after)
    }

    suspend fun getTopPost(authorisation: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getTopPost(authorisation)
    }

    suspend fun getAfterTopPost(authorisation: String, after: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getAfterTopPost(authorisation, after)
    }

    suspend fun getMe(authorisation: String): Response<Me> {
        return RetrofitOauthInstance.api.getMe(authorisation)
    }

    suspend fun getSubredditSearch(authorisation: String, query: String): Response<SubredditSearch> {
        return RetrofitOauthInstance.api.getSubredditSearch(authorisation, query)
    }

    suspend fun getMePrefs(authorisation: String): Response<Prefs> {
        return RetrofitOauthInstance.api.getMePrefs(authorisation)
    }

    suspend fun patchMePrefs(authorisation: String, prefs: Prefs): Response<Prefs> {
        return RetrofitOauthInstance.api.patchMePrefs(authorisation, prefs)
    }

    suspend fun getUserNewPost(authorisation: String, username: String): Response<HomePostList> {
        return  RetrofitOauthInstance.api.getUserNewPost(authorisation, username)
    }

    suspend fun getAfterUserNewPost(authorisation: String, username: String, after: String): Response<HomePostList> {
        return  RetrofitOauthInstance.api.getAfterUserNewPost(authorisation, username, after)
    }

    suspend fun getSubredditDetails(authorisation: String, subName: String): Response<ChildrenData> {
        return RetrofitOauthInstance.api.getSubredditDetails(authorisation, subName)
    }

    suspend fun getSubredditPosts(authorisation: String, subName: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditPosts(authorisation, subName)
    }

    suspend fun getSubredditAfterPosts(authorisation: String, subName: String, after: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditAfterPosts(authorisation, subName, after)
    }

    suspend fun getSubredditHotPosts(authorisation: String, subName: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditHotPosts(authorisation, subName)
    }

    suspend fun getSubredditHotAfterPosts(authorisation: String, subName: String, after: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditHotAfterPosts(authorisation, subName, after)
    }

    suspend fun getSubredditTopPosts(authorisation: String, subName: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditTopPosts(authorisation, subName)
    }

    suspend fun getSubredditTopAfterPosts(authorisation: String, subName: String, after: String): Response<HomePostList> {
        return RetrofitOauthInstance.api.getSubredditTopAfterPosts(authorisation, subName, after)
    }

    suspend fun postSubscribe(authorisation: String, action: String, name: String) {
        return RetrofitOauthInstance.api.postSubscribe(authorisation, action, name)
    }
}