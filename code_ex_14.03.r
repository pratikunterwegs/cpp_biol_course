#### code to print output of ex 14.03

getwd(); setwd("~/git/cpp_biol_course")

library(tidyverse)

data = read_csv("data_code_ex_14.03.csv")

ggplot(data = data, aes(x = time, y = popsize)) + geom_line(aes(group = sim)) + geom_smooth() + theme_classic() + theme(legend.position = "none")



ggsave(filename = "plot_code_ex_14.03_02.png", device = png()); dev.off()
