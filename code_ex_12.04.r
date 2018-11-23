
#### code to print output from ex 12.04 ####
#'load tidyverse
library(tidyverse)

#'list files matching pattern in dir
data.files12.04 = list.files(pattern = "data_ex_12.04")

#'read them in
data = map(data.files12.04, read_csv)

#'assign a covariance
for(i in 1:3){data[[i]]$variance = i * 0.02}

#'bind rows
data = data %>% bind_rows()

#'gather trait and preference
data = gather(data, var, value, -time, -variance)

#'plot
ggplot(data)+geom_point(aes(x = time, y = value, col = var), size = 0.2)+facet_wrap(~variance)+theme_bw()+theme(legend.position = "top")

#'save plot
ggsave(filename = "plot_ex_12.04.png", device = png());dev.off()
