module Main where

import Lib
import Data.Maybe ( fromJust )
import System.Environment ( getArgs )
import System.Exit ( exitSuccess )

main :: IO()
main = do
    x <- getArgs
    let opts = getOpts newConf x
    testConf opts
    text <- readFile (getFilepath (fromJust opts))
    let pixels = processText (lines text)
    displayResults (process (fromJust opts) pixels
        (createBase (fromJust opts) 1 (sortPixels pixels)))
    exitSuccess