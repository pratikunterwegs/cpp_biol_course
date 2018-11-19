#### p01_pratik ####

#'read in csv made from from p01_pratik.cpp and print to png

#'load tidyverse libs
library(readr);library(tidyr);library(dplyr)

#'read data
data_pattern = read_csv("~/git/cpp_biol_course/p01_pratik_data.csv", col_names = F)

#'assign colnames
colnames(data_pattern) = as.character(1:ncol(data_pattern))

#'assign row number for plotting
data_pattern = data_pattern %>% mutate(row = 1:nrow(data_pattern))

#'gather row and colwise values to the format x,y,value
data_pattern = gather(data_pattern, col, value, -row) %>% 
  mutate(col = as.numeric(col), value = as.numeric(value))

#'plot as tile, removing legend and reversing y axis
library(ggplot2)
ggplot()+
  geom_tile(data = data_pattern ,aes(x = col, y = row, fill = value))+
  scale_y_reverse()+
  theme_void()+
  theme(legend.position = "none")+
  labs(list(title = "cellular automaton pattern"))

#'save as png
ggsave(filename = "p01_pratik_plot.png", plot = last_plot(), device = png())