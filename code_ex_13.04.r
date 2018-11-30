#### code to plot output from ex 13.04

setwd("~/git/cpp_biol_course")
library(tidyverse)

files = list.files(pattern = "data_code_ex_13.04", full.name = T)

data = map(files, read_csv)
stimulus = c("sine","step")
for(i in 1:length(data)){data[[i]]$stimulus = stimulus[i]}

data = data %>% bind_rows() %>% gather(var, value, -time, -stimulus) %>% filter(var == "V")

ggplot(data, aes(x = time, y = value, col = var))+ geom_line()+ facet_wrap(~stimulus)
