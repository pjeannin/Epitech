//
// Created by Pierre Jeannin on 31/05/2021.
//

#include "../include/Trade.hpp"

void Trade::run() {
    std::string input;
    while (std::getline(std::cin, input)) {
        if (!input.empty()) {
            char *token = std::strtok(strdup(input.c_str())," ");
            do {
                _inputArgs.push_back(token);
                token = std::strtok(nullptr, " ");
            } while (token);
            switch (getCommand(_inputArgs.front())) {
                case SETTING:
                    settings();
                    break;
                case UPDATE:
                    update();
                    break;
                case ACTION:
                    action();
                    break;
            }
        }
    }
}

Trade::CommandId Trade::getCommand(const std::string &cmd) {
    if (cmd == "update")
        return (UPDATE);
    else if (cmd == "settings")
        return (SETTING);
    else if (cmd == "action")
        return (ACTION);
    return ((CommandId)-1);
}

void Trade::settings() {
    char *endPtr;

    switch (Settings::getSetting(_inputArgs[1])) {
        case Settings::TIMEBANK:
            _settings.setTimebank(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::TIME_PER_MOVE:
            _settings.setTimePerMove(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::PLAYER_NAMES:
            _settings.setPlayerName(_inputArgs.back());
            break;
        case Settings::BOT:
            _settings.setBot(_inputArgs.back());
            break;
        case Settings::CANDLE_INTERVAL:
            _settings.setCandleInterval(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::CANDLES_TOTAL:
            _settings.setCandlesTotal(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::CANDELS_GIVEN:
            _settings.setCandlesGiven(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::INITIAL_STACK:
            _settings.setInitialStack(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::TRANSACTION_FEE_PERCENT:
            _settings.setTransactionFeePercent(std::atoi(_inputArgs.back().c_str()));
            break;
        case Settings::CANDLE_FORMAT:
            _settings.setCandleFormat(_inputArgs.back());
            break;
    }
}

void Trade::update() {
    std::vector<CandleFormatId> candleOrder;
    std::vector<char *> list;
    std::vector<char *> canList;
    int pos = 0;
    char *token1;
    char *token2;
    char *token3;
    char *token4;
    if (_inputArgs[1] != "game")
        return;
    switch (getUpdate(_inputArgs[2])) {
        case NEXT_CANDLE:
            candleOrder = getCandleOrder(const_cast<char *>(_settings.getCandleFormat().c_str()));
            token1 = std::strtok(const_cast<char *>(_inputArgs.back().c_str()), ";");
            do {
                list.push_back(token1);
                token1 = std::strtok(nullptr, ";");
            } while (token1);
            pos = getPairPos(candleOrder);
            for (int i = 0; i < list.size(); ++i) {
                token2 = std::strtok(list[i], ",");
                do {
                    canList.push_back(token2);
                    token2 = std::strtok(nullptr, ",");
                } while (token2);
                if (std::string(canList[pos]) == "BTC_ETH")
                    _update.BTC_ETH.push_back(fillCandle(canList, candleOrder));
                else if (std::string(canList[pos]) == "USDT_ETH")
                    _update.USDT_ETH.push_back(fillCandle(canList, candleOrder));
                else if (std::string(canList[pos]) == "USDT_BTC")
                    _update.USDT_BTC.push_back(fillCandle(canList, candleOrder));
                canList.clear();
            }
            break;
        case STACKS:
            break;
    }
}

void Trade::action() {

}

Trade::UpdateId Trade::getUpdate(const std::string &cmd) {
    if (cmd == "next_candles")
        return NEXT_CANDLE;
    else if (cmd == "stacks")
        return STACKS;
    return (UpdateId)-1;
}

std::vector<Trade::CandleFormatId> Trade::getCandleOrder(char *candleOrder) {
    std::cout << candleOrder << std::endl;
    std::vector<CandleFormatId> retVal;
    char *token = std::strtok(candleOrder, ",");

    do {
        retVal.push_back(getCandleFormatId(token));
        token = std::strtok(nullptr, ",");
    } while (token);
    return retVal;
}

Trade::CandleFormatId Trade::getCandleFormatId(const std::string &cmd) {
    if (cmd == "pair")
        return PAIR;
    else if (cmd == "date")
        return DATE;
    else if (cmd == "high")
        return HIGH;
    else if (cmd == "low")
        return LOW;
    else if (cmd == "open")
        return OPEN;
    else if (cmd == "close")
        return CLOSE;
    else if (cmd == "volume")
        return VOLUME;
    return (CandleFormatId)-1;
}

int Trade::getPairPos(std::vector<CandleFormatId> candleOrder) {
    int i = 0;

    for (; candleOrder[i] != PAIR; ++i);
    return (i);
}

Candle Trade::fillCandle(std::vector<char *> candle, std::vector<CandleFormatId> order) {
    Candle ret;

    for (int i = 0; i < candle.size(); ++i)
        switch (order[i]) {
            case DATE:
                ret.setDate(std::atoi(candle[i]));
                break;
            case HIGH:
                ret.setHigh(std::atof(candle[i]));
                break;
            case LOW:
                ret.setLow(std::atof(candle[i]));
                break;
            case OPEN:
                ret.setOpen(std::atof(candle[i]));
                break;
            case CLOSE:
                ret.setClose(std::atof(candle[i]));
                break;
            case VOLUME:
                ret.setVolume(std::atof(candle[i]));
                break;
        }
    return ret;
}

Settings::SettingId Settings::getSetting(std::string setting) {
    if (setting == "timebank")
        return TIMEBANK;
    else if (setting == "time_per_move")
        return TIME_PER_MOVE;
    else if (setting == "candle_interval")
        return CANDLE_INTERVAL;
    else if (setting == "candles_total")
        return CANDLES_TOTAL;
    else if (setting == "candles_given")
        return CANDELS_GIVEN;
    else if (setting == "initial_stack")
        return INITIAL_STACK;
    else if (setting == "transaction_fee_percent")
        return TRANSACTION_FEE_PERCENT;
    else if (setting == "player_names")
        return PLAYER_NAMES;
    else if (setting == "your_bot")
        return BOT;
    else if (setting == "candle_format")
        return CANDLE_FORMAT;
    return ((SettingId)-1);
}
