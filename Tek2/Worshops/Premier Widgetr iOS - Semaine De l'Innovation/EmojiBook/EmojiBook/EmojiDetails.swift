//
//  File.swift
//  EmojiBook
//
//  Created by LNA on 02/02/2021.
//

import Foundation

public struct EmojiDetails {
    public let emoji:String
    public let name:String
    public let description:String
}

extension EmojiDetails: Identifiable {
    public var id:String {
        emoji
    }
}
