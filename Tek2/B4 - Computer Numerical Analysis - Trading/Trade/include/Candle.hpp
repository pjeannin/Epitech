//
// Created by Pierre Jeannin on 31/05/2021.
//

#ifndef TRADE_CANDLE_HPP
#define TRADE_CANDLE_HPP

class Candle {
    public:
        Candle() = default;
        ~Candle() = default;

        int getDate() const {return _date; }
        void setDate(int date) { _date = date; }
        float getHigh() const { return _high; }
        void setHigh(float high) { _high = high; }
        float getLow() const { return _low; }
        void setLow(float low) { _low = low; }
        float getOpen() const { return _open; }
        void setOpen(float open) { _open = open; }
        float getClose() const { return _close; }
        void setClose(float close) { _close = close; }
        float getVolume() const { return _volume; }
        void setVolume(float volume) { _volume = volume; }

    protected:
    private:
        int _date;
        float _high;
        float _low;
        float _open;
        float _close;
        float _volume;
};

#endif //TRADE_CANDLE_HPP
