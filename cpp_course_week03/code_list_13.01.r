#### plot data from euler integration of lotka-volterra dynamics cpp code listing and ex 13.1

setwd("~/git/cpp_biol_course")
library(tidyverse)

#'plot data code ex 13.01
read_csv("data_code_ex_13.01.csv") %>% gather(var, value, -time) %>% ggplot(aes(x = time, y = value, col = var)) + geom_point() + labs(list(title = "13.01 by euler"))

#' plot lotka volterra model by runge kutta method
read_csv("data_code_ex_13.01_rungekutta_method.csv") %>% gather(var, value, -time) %>% ggplot(aes(x = time, y = value, col = var)) + geom_point() + labs(list(title = "13.01 by runge kutta"));

dev.off()
