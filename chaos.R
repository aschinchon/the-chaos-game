library(Rcpp)
library(tidyverse)

# Import C++ code
sourceCpp('chaos_funcs.cpp')

# Create fractal
df <- createChaos2(10000000, 5, 0, 0)
  
# Do the plot
ggplot(df, aes(x, y)) + 
  geom_point(color="black", shape=46, alpha = 0.01) + 
  coord_equal() +
  theme_void() -> plot
  
# Do you like it? Save it!
ggsave("choose_a_name.png", plot, height = 6, width = 6, units = "in")
  
