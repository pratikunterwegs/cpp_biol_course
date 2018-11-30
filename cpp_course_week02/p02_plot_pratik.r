#### code to plot arterial tree from weekly assignment 02 ####

setwd("~/git/cpp_biol_course")
#' load libs
library(tidyverse)

#' read data
data = read_csv("data_turtle_pos_p02_pratik.csv")

#' plot data
ggplot(data %>% filter(command != "R"), aes(x,y))+
geom_path(aes(group = step, col = as.numeric(step)))+
coord_equal()+
scale_colour_gradientn(colours = c(2,3))+
theme_void()+theme(legend.position = "none")

#' save ggplot
ggsave(filename = "p02_plot_pratik_arterial_tree.png", device = png()); dev.off()
