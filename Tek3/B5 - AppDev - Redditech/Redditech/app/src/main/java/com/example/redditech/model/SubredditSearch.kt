package com.example.redditech.model

data class SubredditData (
    val title: String,
    val header_img: String,
    val display_name: String,
    val icon_img: String,
    val display_name_prefixed: String,
    val subscribers: Int,
    val public_description: String,
    val community_icon: String,
    val banner_background_image: String,
    val header_title: String,
    val created: Float,
    val banner_img: String,
    val description: String,
    var user_is_subscriber: Boolean
)

data class ChildrenData (
    val kind: String,
    val data: SubredditData
)

data class SearchData (
    val after: String,
    val dist: Int,
    val children: List<ChildrenData>
)

data class SubredditSearch (
    val kind: String,
    val data: SearchData
)