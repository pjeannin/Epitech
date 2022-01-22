package com.example.redditech.viewModels

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.redditech.model.*
import com.example.redditech.repository.Repository
import kotlinx.coroutines.launch
import retrofit2.Response

class MainViewModel(private val repository: Repository): ViewModel() {

    val accessToken: MutableLiveData<Response<AccessToken>> = MutableLiveData()
    val hotPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val afterHotPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val topPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val afterTopPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val newPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val afterNewPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val me: MutableLiveData<Response<Me>> = MutableLiveData()
    val userNewPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val userAfterNewPost: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditSearch: MutableLiveData<Response<SubredditSearch>> = MutableLiveData()
    val subredditDetails: MutableLiveData<Response<ChildrenData>> = MutableLiveData()
    val subredditPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditAfterPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditHotPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditHotAfterPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditTopPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val subredditTopAfterPosts: MutableLiveData<Response<HomePostList>> = MutableLiveData()
    val prefs: MutableLiveData<Response<Prefs>> = MutableLiveData()

    fun getAccessToken(authorisation: String, code: String) {
        viewModelScope.launch {
            val response = repository.getAccessToken(authorisation, code)
            accessToken.value = response
        }
    }

    fun getHotPost(authorisation: String) {
        viewModelScope.launch {
            val response = repository.getHotPost(authorisation)
            hotPost.value = response
        }
    }

    fun getAfterHotPost(authorisation: String, after: String) {
        viewModelScope.launch {
            val response = repository.getAfterHotPost(authorisation, after)
            afterHotPost.value = response
        }
    }

    fun getTopPost(authorisation: String) {
        viewModelScope.launch {
            val response = repository.getTopPost(authorisation)
            topPost.value = response
        }
    }

    fun getAfterTopPost(authorisation: String, after: String) {
        viewModelScope.launch {
            val response = repository.getAfterTopPost(authorisation, after)
            afterTopPost.value = response
        }
    }

    fun getNewPost(authorisation: String) {
        viewModelScope.launch {
            val response = repository.getNewPost(authorisation)
            newPost.value = response
        }
    }

    fun getAfterNewPost(authorisation: String, after: String) {
        viewModelScope.launch {
            val response = repository.getAfterNewPost(authorisation, after)
            afterNewPost.value = response
        }
    }

    fun getMe(authorisation: String) {
        viewModelScope.launch {
            val response = repository.getMe(authorisation)
            me.value = response
        }
    }

    fun getUserNewPost(authorisation: String, username: String) {
        viewModelScope.launch {
            val response = repository.getUserNewPost(authorisation, username)
            userNewPost.value = response
        }
    }

    fun getUseAfterNewPost(authorisation: String, username: String, after: String) {
        viewModelScope.launch {
            val response = repository.getAfterUserNewPost(authorisation, username, after)
            userNewPost.value = response
        }
    }

    fun getSubredditSearch(authorisation: String, query: String) {
        viewModelScope.launch {
            val response = repository.getSubredditSearch(authorisation, query)
            subredditSearch.value = response
        }
    }

    fun getSubredditDetails(authorisation: String, subredditName: String) {
        viewModelScope.launch {
            val response = repository.getSubredditDetails(authorisation, subredditName)
            subredditDetails.value = response
        }
    }

    fun getSubredditPost(authorisation: String, subredditName: String) {
        viewModelScope.launch {
            val response = repository.getSubredditPosts(authorisation, subredditName)
            subredditPosts.value = response
        }
    }

    fun getPrefs(authorisation: String) {
        viewModelScope.launch {
            val response = repository.getMePrefs(authorisation)
            prefs.value = response
        }
    }

    fun patchPrefs(authorisation: String, prefs: Prefs) {
        viewModelScope.launch {
            repository.patchMePrefs(authorisation, prefs)
        }
    }

    fun getSubredditAfterPost(authorisation: String, subredditName: String, after: String) {
        viewModelScope.launch {
            val response = repository.getSubredditAfterPosts(authorisation, subredditName, after)
            subredditAfterPosts.value = response
        }
    }

    fun getSubredditHotPost(authorisation: String, subredditName: String) {
        viewModelScope.launch {
            val response = repository.getSubredditHotPosts(authorisation, subredditName)
            subredditHotPosts.value = response
        }
    }

    fun getSubredditHotAfterPost(authorisation: String, subredditName: String, after: String) {
        viewModelScope.launch {
            val response = repository.getSubredditHotAfterPosts(authorisation, subredditName, after)
            subredditHotAfterPosts.value = response
        }
    }

    fun getSubredditTopPost(authorisation: String, subredditName: String) {
        viewModelScope.launch {
            val response = repository.getSubredditTopPosts(authorisation, subredditName)
            subredditTopPosts.value = response
        }
    }

    fun getSubredditTopAfterPost(authorisation: String, subredditName: String, after: String) {
        viewModelScope.launch {
            val response = repository.getSubredditTopAfterPosts(authorisation, subredditName, after)
            subredditTopAfterPosts.value = response
        }
    }

    fun postSubscribe(authorisation: String, action: String, name: String) {
        viewModelScope.launch {
            repository.postSubscribe(authorisation, action, name)
        }
    }
}