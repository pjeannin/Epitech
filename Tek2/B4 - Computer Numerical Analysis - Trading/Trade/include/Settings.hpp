//
// Created by Pierre Jeannin on 31/05/2021.
//

#ifndef TRADE_SETTINGS_HPP
#define TRADE_SETTINGS_HPP

#include <string>

class Settings {
    public:
        enum SettingId {
            TIMEBANK,
            TIME_PER_MOVE,
            PLAYER_NAMES,
            BOT,
            CANDLE_INTERVAL,
            CANDLES_TOTAL,
            CANDELS_GIVEN,
            INITIAL_STACK,
            TRANSACTION_FEE_PERCENT,
            CANDLE_FORMAT
        };
        Settings() = default;
        ~Settings() = default;
        static SettingId getSetting(std::string setting);

        int getTimebank() const { return _timebank; }
        void setTimebank(int value) { _timebank = value; }
        int getTimePerMove() const { return _timePerMove; }
        void setTimePerMove(int value) { _timePerMove = value; }
        int getCandleInterval() const { return _candleInterval; }
        void setCandleInterval(int value) { _candleInterval = value; }
        int getCandlesTotal() const { return _candlesTotal; }
        void setCandlesTotal(int value) { _candlesTotal = value; }
        int getCandlesGiven() const { return _candlesGiven; }
        void setCandlesGiven(int value) { _candlesGiven = value; }
        int getInitialStack() const { return _initialStack; }
        void setInitialStack(int value) { _initialStack = value; }
        int getTransactionFeePercent() const { return _transactionFeePercent; }
        void setTransactionFeePercent(int value) { _transactionFeePercent = value; }
        const std::string &getPlayerName() const { return _playerName; }
        void setPlayerName(const std::string &value) { _playerName = value; }
        const std::string &getBot() const { return _bot; }
        void setBot(const std::string &value) { _bot = value; }
        const std::string &getCandleFormat() const { return _candleFormat; }
        void setCandleFormat(const std::string &value) { _candleFormat = value; }

    protected:
    private:
        int _timebank;
        int _timePerMove;
        int _candleInterval;
        int _candlesTotal;
        int _candlesGiven;
        int _initialStack;
        int _transactionFeePercent;
        std::string _playerName;
        std::string _bot;
        std::string _candleFormat;
};

#endif //TRADE_SETTINGS_HPP
