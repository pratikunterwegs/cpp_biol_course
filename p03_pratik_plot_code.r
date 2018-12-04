
#### code to summarise and plot data from p03_pratik.cpp output ####
#' output file is data_p03_pratik.csv

#'verify working directory and load libs
getwd()
setwd("~/git/cpp_biol_course/")
library(tidyverse)

#'read in data and summarise mean elongation rate
data = read_csv("data_p03_pratik.csv") %>% 
  mutate(rate = (length_final - length_start)/time_steps)
head(data)
dim(data)

#'plot elongation rate (velocity) ~ force

force_stall = 13*(1.385e-23)*298*log(200/50)/(8e-9)

force_stall

ggplot(data, aes(x = force, y = rate/1e-6)) + geom_point() + geom_vline(xintercept = force_stall) + labs(list(x = "force", y = "elongation rate"))

ggsave(filename = "p03_pratik_plot.png", device = png()); dev.off()
