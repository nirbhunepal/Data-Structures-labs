#include "gradable.h"

Gradable::Gradable(std::string donor_name, int donor_year)
    : DonorName{donor_name}, DonorDate{donor_year}, Rating{0.0}, Price{0.0} {}

void Gradable::Grade() {
    Rating = 90.0;
}

void Gradable::Value() {
    Price = 195e6;
}
double Gradable::getPrice() const {
    return Price;
}

double Gradable::getRating() const {
    return Rating;
}
void Gradable::setPrice(double new_price) {
    Price = new_price;
}

void Gradable::setRating(double new_rating) {
    Rating = new_rating;
}

