#### p01_pratik ####

#### rule 30 #####
#'print pattern from rule 30

library(readr);library(tidyr);library(dplyr)
data_pattern = read_csv("~/git/cpp_biol_course/p01_pratik_data.csv", col_names = F)

colnames(data_pattern) = as.character(1:250)

data_pattern = data_pattern %>% mutate(row = 1:nrow(data_pattern))

#library(tidyr)
data_pattern = gather(data_pattern, col, value, -row) %>% 
  mutate(col = as.numeric(col), value = as.numeric(value))

library(ggplot2)
ggplot()+
  geom_tile(data = data_pattern ,aes(x = col, y = row, fill = value))+
  scale_y_reverse()+
  theme_void()+
  theme(legend.position = "none")+
  labs(list(title = "cellular automaton pattern"))

ggsave(filename = "p01_pratik_plot.png", plot = last_plot(), device = png())