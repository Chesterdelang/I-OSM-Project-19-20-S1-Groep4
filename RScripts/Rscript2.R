resultsPerDay1 <- read.csv("resultsPerDay1.csv", header = TRUE)
resultsPerDay2 <- read.csv("resultsPerDay2.csv", header = TRUE)
resultsPerDay3 <- read.csv("resultsPerDay3.csv", header = TRUE)
resultsPerDay4 <- read.csv("resultsPerDay4.csv", header = TRUE)
resultsPerDay5 <- read.csv("resultsPerDay5.csv", header = TRUE)

Data1 <- resultsPerDay1[,-2] 
Data2 <- resultsPerDay2[,-2] 
Data3 <- resultsPerDay3[,-2] 
Data4 <- resultsPerDay4[,-2] 
Data5 <- resultsPerDay5[,-2] 

names(Data1)[2] <- "ProducedDay"
names(Data2)[2] <- "ProducedDay"
names(Data3)[2] <- "ProducedDay"
names(Data4)[2] <- "ProducedDay"
names(Data5)[2] <- "ProducedDay"

min(Data1$ProducedDay, na.rm = TRUE)
min(Data2$ProducedDay, na.rm = TRUE)
min(Data3$ProducedDay, na.rm = TRUE)
min(Data4$ProducedDay, na.rm = TRUE)
min(Data5$ProducedDay, na.rm = TRUE)

max(Data1$ProducedDay, na.rm = TRUE)
max(Data2$ProducedDay, na.rm = TRUE)
max(Data3$ProducedDay, na.rm = TRUE)
max(Data4$ProducedDay, na.rm = TRUE)
max(Data5$ProducedDay, na.rm = TRUE)

library(ggplot2)
install.packages("ggthemes") 
library(ggthemes)

d2 <- ggplot(Data4, aes(X, ProducedDay))
d1 <- ggplot(Data1, aes(ProducedDay)) 

d2 + 
  geom_point(data = Data1, position = 'stack', stat = 'identity', color = "blue") +
  geom_point(data = Data2, color = "red") +
  geom_point(data = Data3, color = "Green") +
  geom_point(data = Data4, color = "Yellow") +
  xlab("Day of production") + 
  ylab("Amount produced per day") + 
  scale_y_continuous(limits = c(0, 1100)) +
  scale_x_continuous(limits = c(3000, 3200))

d1 +
  geom_freqpoly(data = Data1, color = "red") +
  geom_freqpoly(data = Data2, color = "Blue") +
  geom_freqpoly(data = Data3, color = "Brown") +
  geom_freqpoly(data = Data4, color = "Yellow") +
  geom_freqpoly(data = Data5, color = "Green") +
  xlab("Produced per day") +
  ylab("Count per day") +
  scale_y_continuous(limits = c(0, 750)) +
  scale_x_continuous(limits = c(0, 1000))


d1 + 
  geom_bar(color = "blue") +
  theme_hc()

d2 + 
  geom_bin2d(data = Data1) +
  geom_bin2d(data = Data2) +
  geom_bin2d(data = Data3) +
  geom_bin2d(data = Data3) +
  geom_bin2d(data = Data5) +
  xlab("Day of production") + 
  ylab("Produced per day")