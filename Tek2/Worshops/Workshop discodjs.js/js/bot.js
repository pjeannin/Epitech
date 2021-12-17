const Discord = require('discord.js');
const client = new Discord.Client();
const token = require("../json/token.json")
const config = require("../json/config.json")

client.on('ready', () => {
    console.log("Ready to go !");
    client.user.setPresence({
        status: "online",
        activity: {
            name: config.status,
            type: "PLAYING",
        }
    });
});

client.on('message', message => {
    if (message.author.bot) return;

    // Ex 0 : Le bot ne doit traiter que les messages comprennant le prefix '!'
    if (message.content.substring(0, 1) != config.prefix) return;

    // Ex 1 : Afficher la commande que l'on a écrit dans la console
    console.log(message.content);

    // Ex 2 : Quand l'utilisateur envoi la commande !ping, on répond pong
    if (message.content == config.prefix + 'ping')
        message.reply('pong');

    // Ex 3 : Quand la commande est au format !kick @user, kicker l'utilisateur mentionné
    const args = message.content.slice(1).trim().split(/ +/g);
    const command = args.shift().toLowerCase();
    if (command === "kick") {
        let kUser = message.guild.member(message.mentions.users.first());
        if (!kUser) return message.channel.send("Je n'ai pas trouvé l'utilisateur");
        if (!message.member.hasPermission("KICK_MEMBERS")) return message.channel.send("Permission refusée");
        if (kUser.hasPermission("KICK_MEMBERS")) return message.channel.send("Cette personne ne peut pas être kick !");

        message.guild.member(kUser).kick();
        message.delete();
    }

    // Ex 4 : Quand la commande est du format !ban @user, bannir l'utilisateur mentionné
    if (command === "ban") {
        let bUser = message.guild.member(message.mentions.users.first());
        if (!bUser) return message.channel.send("Je n'ai pas trouvé l'utilisateur");
        if (!message.member.hasPermission("BAN_MEMBERS")) return message.channel.send("Permission refusée");
        if (bUser.hasPermission("BAN_MEMBERS")) return message.channel.send("Cette personne ne peut pas être ban !");

        message.guild.member(bUser).ban();
        message.delete();
    }
})

client.on('channelCreate', (channel) => {
    console.log(`Channel ${channel.name} de type ${channel.type} créé`);
})

// Ex 6 : Quand un utilisateur est banni, afficher un message dans la console le nom de la personne banni

client.on('guildBanAdd', (guild, user) => {
    console.log(`${user.username} a été banni du discord`);
})

// Ex 7 : Quand un utilisateur est dé-banni, afficher un message dans la console avec le nom de la personne dé-banni

client.on('guildBanRemove', (guild, user) => {
    console.log(`${user.username} a été unban du discord`);
})

// Ex Bonus : Essayez de gérer autant d'event que possible (Invitations / Roles / Messages / Guild / ...) (cf: discord.js.org/#/docs)


client.login(token.token);
