//
//  Emojibook_Widgget.swift
//  Emojibook Widgget
//
//  Created by LNA on 02/02/2021.
//

import WidgetKit
import SwiftUI

struct Provider: TimelineProvider {
    func placeholder(in context: Context) -> SimpleEntry {
        SimpleEntry(date: Date(), emojiDetails: EmojiProvider.random())
    }

    func getSnapshot(in context: Context, completion: @escaping (SimpleEntry) -> ()) {
        _ = SimpleEntry(date: Date(), emojiDetails: EmojiProvider.random())
    }

    func getTimeline(in context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        var entries: [SimpleEntry] = []

        // Generate a timeline consisting of five entries an hour apart, starting from the current date.
        let currentDate = Date()
        for hourOffset in 0 ..< 5 {
            let entryDate = Calendar.current.date(byAdding: .hour, value: hourOffset, to: currentDate)!
            let entry = SimpleEntry(date: entryDate, emojiDetails: EmojiProvider.random())
            entries.append(entry)
        }

        let timeline = Timeline(entries: entries, policy: .atEnd)
        completion(timeline)
    }
}

struct SimpleEntry: TimelineEntry {
    let date: Date
    public let emojiDetails: EmojiDetails
}

struct Emojibook_WidggetEntryView : View {
    var entry: Provider.Entry

    var body: some View {
        EmojiWidgetView(emojiDetails: entry.emojiDetails)
    }
}

@main
struct Emojibook_Widgget: Widget {
    let kind: String = "Emojibook_Widgget"

    var body: some WidgetConfiguration {
        StaticConfiguration(
            kind: kind,
            provider: Provider()
        ) { entry in
            Emojibook_WidggetEntryView(entry: entry)
        }
        .configurationDisplayName("Random Emoji")
        .description("Display a widget with an emoji that is updated randomly")
        .supportedFamilies([.systemSmall])
    }
}

struct Emojibook_Widgget_Previews: PreviewProvider {
    static var previews: some View {
        Emojibook_WidggetEntryView(entry: SimpleEntry(date: Date(), emojiDetails: EmojiProvider.random()))
            .previewContext(WidgetPreviewContext(family: .systemSmall))
    }
}
