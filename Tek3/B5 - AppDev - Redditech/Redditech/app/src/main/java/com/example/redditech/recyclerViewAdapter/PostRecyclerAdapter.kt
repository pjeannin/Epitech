package com.example.redditech.recyclerViewAdapter

import android.content.Context
import android.icu.text.SimpleDateFormat
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.R
import com.example.redditech.model.Post
import com.squareup.picasso.Picasso
import java.time.format.DateTimeFormatter
import java.util.*

class PostRecyclerAdapter(private val context: Context): RecyclerView.Adapter<PostRecyclerAdapter.ViewHolder>() {

    private var posts: MutableList<Post> = mutableListOf()
    private var classAfter: String? = null

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.post, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.subredditName.text = posts[position].data.subreddit_name_prefixed
        holder.username.text = context.resources.getString(R.string.prefixed_username, posts[position].data.author)
        holder.postText.text = posts[position].data.title
        holder.upVotes.text = posts[position].data.ups.toString()
        holder.downVotes.text = posts[position].data.downs.toString()
        holder.description.text = posts[position].data.selftext
        Log.d("Post Hint", position.toString())
        if (posts[position].data.post_hint != null) {
            if (posts[position].data.post_hint == "image") {
                Picasso.get().load(posts[position].data.preview.images[0].source.url).into(holder.imageView)
                val layout: ViewGroup.LayoutParams = holder.imageView.layoutParams
                layout.height = 370
                holder.imageView.layoutParams = layout
            }
        }
        if (posts[position].data.sr_detail.community_icon != "" || posts[position].data.sr_detail.icon_img != "")
            Picasso.get()
                .load(if (posts[position].data.sr_detail.icon_img != "") posts[position].data.sr_detail.icon_img else posts[position].data.sr_detail.community_icon)
                .into(holder.profilePicture)
    }

    override fun getItemCount(): Int {
        return posts.size
    }

    inner class ViewHolder(itemView: View): RecyclerView.ViewHolder(itemView) {
        var subredditName: TextView = itemView.findViewById(R.id.subredditName)
        var username: TextView = itemView.findViewById(R.id.username)
        var postText: TextView = itemView.findViewById(R.id.postText)
        var upVotes: TextView = itemView.findViewById(R.id.upVotes)
        var downVotes: TextView = itemView.findViewById(R.id.downVotes)
        var imageView: ImageView = itemView.findViewById(R.id.imageView)
        var description: TextView = itemView.findViewById(R.id.description)
        var profilePicture: ImageView = itemView.findViewById(R.id.subImage)
    }

    fun setData(newList: List<Post>, after: String) {
        classAfter = after
        posts.clear()
        posts.addAll(newList)
        notifyDataSetChanged()
    }

    fun addData(newList: List<Post>, after: String) {
        if (classAfter != after) {
            classAfter = after
            posts.addAll(newList)
            notifyDataSetChanged()
        }
    }
}