package com.example.redditech.model

data class ResolutionsData (
    val url: String,
    val width: Int,
    val height: Int
)

data class SourceData (
    val url: String,
    val width: Int,
    val height: Int

)

data class ImagesData (
    val source: SourceData,
    val resolutions: List<ResolutionsData>
)

data class PreviewData (
    val images: List<ImagesData>,
    val id: String
)

data class RedditVideo (
    val fallback_url: String,
    val dash_url: String
    )

data class SrDetails (
    val community_icon: String,
    val icon_img: String
)


data class PostData (
    val subreddit: String,
    val author_fullname: String,
    val title: String,
    val subreddit_name_prefixed: String,
    val ups: Int,
    val downs: Int,
    val post_hint: String?,
    val created: Float,
    val preview: PreviewData,
    val author: String,
    val num_comments: Int,
    val is_video: Boolean,
    val media: RedditVideo,
    val url: String,
    val selftext: String,
    val sr_detail:SrDetails
)

data class Post (
    val after: String,
    val kind: String,
    val data: PostData,
    val before: String
)
