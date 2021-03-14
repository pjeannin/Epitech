module Main where

import Lib
import Data.Maybe
import System.Environment ( getArgs )
import System.Exit

main :: IO()
main = do
    x <- getArgs
    let opts = getOpts defaultConf x
    testConf opts
    liveDisplay (createFirstLine (fromJust opts) 1 ([' '], [' '], [' ']))
        (fromJust opts) 0 >> exitSuccess