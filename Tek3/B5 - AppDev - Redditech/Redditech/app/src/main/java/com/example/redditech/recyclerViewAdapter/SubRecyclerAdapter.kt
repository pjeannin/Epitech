package com.example.redditech.recyclerViewAdapter

import android.content.Context
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.redditech.R
import com.example.redditech.fragment.AppContainer
import com.example.redditech.model.ChildrenData
import com.squareup.picasso.Picasso

class SubRecyclerAdapter(private var appContainer: AppContainer, private var context: Context): RecyclerView.Adapter<SubRecyclerAdapter.ViewHolder>() {
    private var subs = listOf<ChildrenData>()

    override fun onCreateViewHolder(
        parent: ViewGroup,
        viewType: Int
    ): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.subreddit_title, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.name.text = subs[position].data.display_name_prefixed
        holder.community.text = context.resources.getString(R.string.subscriber, subs[position].data.subscribers)
        holder.itemView.setOnClickListener {
            Log.d("Click", subs[position].data.display_name_prefixed)
            appContainer.goSubDetails(subs[position].data.display_name_prefixed)
        }
        if (subs[position].data.community_icon != "" || subs[position].data.icon_img != "")
            Picasso.get().load(if (subs[position].data.community_icon != "") subs[position].data.community_icon else subs[position].data.icon_img).into(holder.subredditImage)
    }

    override fun getItemCount(): Int {
        return subs.size
    }

    inner class ViewHolder(itemView: View): RecyclerView.ViewHolder(itemView) {
        var subredditImage: ImageView = itemView.findViewById(R.id.subredditImage)
        var name: TextView = itemView.findViewById(R.id.name)
        var community: TextView = itemView.findViewById(R.id.community)
    }

    fun setData(newData: List<ChildrenData>) {
        subs = newData
        notifyDataSetChanged()
    }
}