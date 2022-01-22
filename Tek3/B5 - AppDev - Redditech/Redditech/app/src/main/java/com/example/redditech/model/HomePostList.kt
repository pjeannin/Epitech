package com.example.redditech.model

data class HomePostList (
    val kind: String,
    val data: HomePostLIstData
)

data class HomePostLIstData (
    val after: String,
    val dist: Int,
    val children: List<Post>
)