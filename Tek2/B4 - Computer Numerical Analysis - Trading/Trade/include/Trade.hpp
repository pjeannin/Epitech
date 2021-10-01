//
// Created by Pierre Jeannin on 31/05/2021.
//

#ifndef TRADE_TRADE_HPP
#define TRADE_TRADE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include "Settings.hpp"
#include "Candle.hpp"

typedef struct update {
    float BTC;
    float ETH;
    float USDT;
    float fifty_USDT_BTC;
    float fifty_USDT_ETH;
    float fifty_BTC_ETH;
    std::vector<std::string> sells;
    std::vector<std::string> buys;
    std::vector<float> buy;
    std::vector<float> sell;
    std::vector<Candle> BTC_ETH;
    std::vector<Candle> USDT_ETH;
    std::vector<Candle> USDT_BTC;
} update_t ;

class Trade {
    public:
        Trade() = default;
        ~Trade() = default;
        void run();
    protected:
    private:
        enum CommandId {
            SETTING = 0,
            UPDATE = 1,
            ACTION = 2
        };
        enum UpdateId {
            NEXT_CANDLE,
            STACKS
        };
        enum CandleFormatId {
            PAIR,
            DATE,
            HIGH,
            LOW,
            OPEN,
            CLOSE,
            VOLUME
        };

        static CandleFormatId getCandleFormatId(const std::string &cmd);
        static UpdateId getUpdate(const std::string &cmd);
        static CommandId getCommand(const std::string &cmd);
        int getPairPos(std::vector<CandleFormatId> candleOrder);
        void settings();
        void update();
        void action();
        static std::vector<CandleFormatId> getCandleOrder(char *candleOrder);
        Candle fillCandle(std::vector<char *>candle, std::vector<CandleFormatId> order);

        std::vector<std::string> _inputArgs;
        Settings _settings;
        update_t _update;
};


#endif //TRADE_TRADE_HPP
