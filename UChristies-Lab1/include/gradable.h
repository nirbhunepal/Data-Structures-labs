#ifndef __GRADABLE_H
#define __GRADABLE_H
#include <string>

class Gradable {
public:
    Gradable(std::string donor_name, int donor_year);

    virtual void Grade();
    virtual void Value();

    double getPrice() const;
    double getRating() const;

    void setPrice(double new_price);
    void setRating(double new_rating);

protected:
    std::string DonorName;
    int DonorDate;
    double Rating;
    double Price;
};

#endif
