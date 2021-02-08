//
//  ContentView.swift
//  EmojiBook
//
//  Created by LNA on 02/02/2021.
//

import SwiftUI

struct ContentView: View {

    let emojiData: [EmojiDetails] = EmojiProvider.all()
    @State private var showingDetails: Bool = false
    
    var body: some View {
        NavigationView {
            List {
                ForEach (emojiData, content: { emojiDetails in
                    Button(action: {
                        showingDetails.toggle()
                    }, label: {
                        EmojiItemView(emoji: emojiDetails.emoji, emojiName: emojiDetails.name)
                    })
                    .sheet(isPresented: $showingDetails) {
                        EmojiDetailView(emojiDetails: emojiDetails)
                    }
                })
            }
            .foregroundColor(.black)
            .navigationTitle("EmojiBook")
        }
    }
}

struct EmojiItemView: View {
    let emoji: String
    let emojiName: String
    
    var body: some View {
        Text("\(emoji) \(emojiName)")
            .font(.largeTitle)
            .padding([.top, .bottom])
    }
}

struct EmojiDetailView: View {
    var emojiDetails : EmojiDetails
    
    var body: some View {
        ZStack {
            Color(UIColor.systemIndigo).edgesIgnoringSafeArea(.all)
            
            VStack {
                VStack(alignment: .leading) {
                    HStack {
                        Text("\(emojiDetails.emoji) \(emojiDetails.name)")
                            .font(.largeTitle)
                            .bold()
                    }
                    .padding()
                    
                    Text(emojiDetails.description)
                        .padding([.leading, .trailing, .bottom])
                        .font(.title)
                }
            }
            .foregroundColor(.white)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
