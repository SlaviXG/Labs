data <- read.csv("spotify_artist_data.csv")
frame <- data.frame(data)

#deleting the numeration column
frame <- frame[,-1]

#renaming the columns
names(frame)[1] <- "artist_name"
names(frame)[2] <- "lead_streams"
names(frame)[3] <- "feats"
names(frame)[4] <- "tracks"
names(frame)[5] <- "one_billion"
names(frame)[6] <- "hundred_million"
names(frame)[7] <- "last_updated"

frame$lead_streams <- as.numeric(gsub("[^0-9.]", "", frame$lead_streams))
frame$feats <- as.numeric(gsub("[^0-9.]", "", frame$feats))
frame$tracks <- as.numeric(gsub("[^0-9.]", "", frame$tracks))
#restructing the number of tracks for informative plots
frame <- frame[frame$tracks <= 1000, ]

#adding the data without N/A to the corresponding columns
without_na <- na.omit(frame)
lead_streams <- sort(without_na$lead_streams)
feats <- sort(without_na$feats)
tracks <- sort(without_na$tracks)

#empirical distribution density function
#creating an array of values with the function c()
#s - lead streams, f - feats, t - tracks
s=c(lead_streams)
f=c(feats)
t=c(tracks)

par(mar = c(3, 4, 2, 2)) # set bottom, left, top, and right margins
plot(density(s),col=2,lwd=2,xlab="X",main="Empirical distribution density function of 'Lead streams'", col.main=5,cex.main=1.5)
plot(density(f),col=2,lwd=2,xlab="X",main="Empirical distribution density function of 'Feats'", col.main=5,cex.main=1.5)
plot(density(t),col=2,lwd=2,xlab="X",main="Empirical distribution density function of 'Tracks'", col.main=5,cex.main=1.5)

#frequency polygon
hist(lead_streams)
h1 <- hist(lead_streams)
lines(h1$counts ~ h1$mids, col = "#D4886A", lwd = 2)
rug(lead_streams)

hist(feats)
h2 <- hist(feats)
lines(h2$counts ~ h2$mids, col="green", lwd = 2)
rug(feats)

hist(tracks)
h3 <- hist(tracks)
lines(h3$counts ~ h3$mids, col="#73AC96", lwd = 2)
rug(tracks)

#box and whisker plot
boxplot(s,
        main = "Lead Streams",
        xlab = "Count",
        ylab = "Result",
        col = "#C7F1E1",
        border = "#053E28",
        horizontal = TRUE,
        notch = TRUE
)

boxplot(f,
        main = "Feats",
        xlab = "Count",
        ylab = "Result",
        col = "#C7F1E1",
        border = "#053E28",
        horizontal = TRUE,
        notch = TRUE
)

boxplot(t,
        main = "Tracks",
        xlab = "Count",
        ylab = "Result",
        col = "#C7F1E1",
        border = "#053E28",
        horizontal = TRUE,
        notch = TRUE
)

#calculate sample values
cat("Lead streams: ", "\n")
max <- max(s)
cat("Max: ", max, "\n")
min <- min(s)
cat("Min: ", min, "\n")
median <- median(s)
cat("Median: ", median, "\n")
quartile_1 <- quantile(s, 0.25)
cat("quartile_1: ", quartile_1, "\n")
quartile_2 <- quantile(s, 0.50)
cat("quartile_2: ", quartile_2, "\n")
quartile_3 <- quantile(s, 0.75)
cat("quartile_3: ", quartile_3, "\n")
decile_1 <- quantile(s, 0.1)
cat("decile_1: ", decile_1, "\n")
decile_2 <- quantile(s, 0.2)
cat("decile_2: ", decile_2, "\n")
decile_3 <- quantile(s, 0.3)
cat("decile_3: ", decile_3, "\n")
decile_4 <- quantile(s, 0.4)
cat("decile_4: ", decile_4, "\n")
decile_5 <- quantile(s, 0.5)
cat("decile_5: ", decile_5, "\n")
decile_6 <- quantile(s, 0.6)
cat("decile_6: ", decile_6, "\n")
decile_7 <- quantile(s, 0.7)
cat("decile_7: ", decile_7, "\n")
decile_8 <- quantile(s, 0.8)
cat("decile_8: ", decile_8, "\n")
decile_9 <- quantile(s, 0.9)
cat("decile_9: ", decile_9, "\n")

cat("Feats: ", "\n")
max <- max(f)
cat("Max: ", max, "\n")
min <- min(f)
cat("Min: ", min, "\n")
median <- median(f)
cat("Median: ", median, "\n")
quartile_1 <- quantile(f, 0.25)
cat("quartile_1: ", quartile_1, "\n")
quartile_2 <- quantile(f, 0.50)
cat("quartile_2: ", quartile_2, "\n")
quartile_3 <- quantile(f, 0.75)
cat("quartile_3: ", quartile_3, "\n")
decile_1 <- quantile(f, 0.1)
cat("decile_1: ", decile_1, "\n")
decile_2 <- quantile(f, 0.2)
cat("decile_2: ", decile_2, "\n")
decile_3 <- quantile(f, 0.3)
cat("decile_3: ", decile_3, "\n")
decile_4 <- quantile(f, 0.4)
cat("decile_4: ", decile_4, "\n")
decile_5 <- quantile(f, 0.5)
cat("decile_5: ", decile_5, "\n")
decile_6 <- quantile(f, 0.6)
cat("decile_6: ", decile_6, "\n")
decile_7 <- quantile(f, 0.7)
cat("decile_7: ", decile_7, "\n")
decile_8 <- quantile(f, 0.8)
cat("decile_8: ", decile_8, "\n")
decile_9 <- quantile(f, 0.9)
cat("decile_9: ", decile_9, "\n")

cat("Tracks: ", "\n")
max <- max(t)
cat("Max: ", max, "\n")
min <- min(t)
cat("Min: ", min, "\n")
median <- median(t)
cat("Median: ", median, "\n")
quartile_1 <- quantile(t, 0.25)
cat("quartile_1: ", quartile_1, "\n")
quartile_2 <- quantile(t, 0.50)
cat("quartile_2: ", quartile_2, "\n")
quartile_3 <- quantile(t, 0.75)
cat("quartile_3: ", quartile_3, "\n")
decile_1 <- quantile(t, 0.1)
cat("decile_1: ", decile_1, "\n")
decile_2 <- quantile(t, 0.2)
cat("decile_2: ", decile_2, "\n")
decile_3 <- quantile(t, 0.3)
cat("decile_3: ", decile_3, "\n")
decile_4 <- quantile(t, 0.4)
cat("decile_4: ", decile_4, "\n")
decile_5 <- quantile(t, 0.5)
cat("decile_5: ", decile_5, "\n")
decile_6 <- quantile(t, 0.6)
cat("decile_6: ", decile_6, "\n")
decile_7 <- quantile(t, 0.7)
cat("decile_7: ", decile_7, "\n")
decile_8 <- quantile(t, 0.8)
cat("decile_8: ", decile_8, "\n")
decile_9 <- quantile(t, 0.9)
cat("decile_9: ", decile_9, "\n")

#characteristics of the position of the center of values
expected_value=mean(s)
cat("1.	Expected value: ", expected_value, "\n")
mean_geometric=exp(mean(log(s)))
cat("2.	Geometric mean: ", mean_geometric, "\n")
mean_harmonic = length(s)/sum(1/s)
cat("3.	Harmonic mean: ", mean_harmonic, "\n")
moda <- function(s){
  ux <- unique(s)
  ux[which.max(tabulate(match(s, ux)))]
}
moda(s)

expected_value=mean(f)
cat("1.	Expected value: ", expected_value, "\n")
mean_geometric=exp(mean(log(f)))
cat("2.	Geometric mean: ", mean_geometric, "\n")
mean_harmonic = length(f)/sum(1/f)
cat("3.	Harmonic mean: ", mean_harmonic, "\n")
moda(f)

expected_value=mean(t)
cat("1.	Expected value: ", expected_value, "\n")
mean_geometric=exp(mean(log(t)))
cat("2.	Geometric mean: ", mean_geometric, "\n")
mean_harmonic = length(t)/sum(1/t)
cat("3.	Harmonic mean: ", mean_harmonic, "\n")
moda(t)

#dispersion characteristics
dispersion <- mean((s - mean(s))^2)
print(dispersion)
standard_deviation <- sqrt(dispersion)
print(standard_deviation)
coefficient_of_variation <- standard_deviation / mean(s)
print(coefficient_of_variation)
probability_range <- 1/2*(quantile(s, probs=0.75)-quantile(s, probs=0.25))
print(probability_range)
range <- max(s) - min(s)
print(range)
interquartile_range <- quantile(s, 0.75) - quantile(s, 0.25)
print(interquartile_range)

dispersion <- mean((f - mean(f))^2)
print(dispersion)
standard_deviation <- sqrt(dispersion)
print(standard_deviation)
coefficient_of_variation <- standard_deviation / mean(f)
print(coefficient_of_variation)
probability_range <- 1/2*(quantile(f, probs=0.75)-quantile(f, probs=0.25))
print(probability_range)
range <- max(f) - min(f)
print(range)
interquartile_range <- quantile(f, 0.75) - quantile(f, 0.25)
print(interquartile_range)

dispersion <- mean((t - mean(t))^2)
print(dispersion)
standard_deviation <- sqrt(dispersion)
print(standard_deviation)
coefficient_of_variation <- standard_deviation / mean(t)
print(coefficient_of_variation)
probability_range <- 1/2*(quantile(t, probs=0.75)-quantile(t, probs=0.25))
print(probability_range)
range <- max(t) - min(t)
print(range)
interquartile_range <- quantile(t, 0.75) - quantile(t, 0.25)
print(interquartile_range)

#analysis of asymmetry and peaked distribution
asymmetry_coefficient<-function(a){
  n=length(a)
  n/(n-1)/(n-2)*sum(((a-mean(a))/sd(a))^3)
}

asymmetry_coefficient(s)
asymmetry_coefficient(f)
asymmetry_coefficient(t)

kurtosis_coefficient<-function(a){
  n=length(a)
  n*(n+1)/(n-1)/(n-2)/(n-3)*sum(((a-mean(a))/sd(a))^4)-3*((n-1)^2)/(n-2)/(n-3)
}

kurtosis_coefficient(s)
kurtosis_coefficient(f)
kurtosis_coefficient(t)

#normal Q-Q Plot 
qqnorm(s, xlab = "Теоретичні квантилі", ylab = "Sample quantiles")
qqline(s, col = "#F8BF90", lwd = 2)
qqnorm(f, xlab = "Теоретичні квантилі", ylab = "Sample quantiles")
qqline(f, col = "#F8BF90", lwd = 2)
qqnorm(t, xlab = "Теоретичні квантилі", ylab = "Sample quantiles")
qqline(t, col = "#F8BF90", lwd = 2)

