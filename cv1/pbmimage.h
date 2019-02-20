#ifndef PRC_PBMIMAGE_H
#define PRC_PBMIMAGE_H

#include <istream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iostream>

class PbmImage {
public:
    using Bit = bool;

private:
    std::vector<std::vector<Bit>> pbmBits;
    using vectorColumnType = decltype(pbmBits);
    using vectorRowType = vectorColumnType::value_type;
    using PbmDimensions = std::pair<vectorColumnType::size_type, vectorRowType::size_type>;

    bool readPbmHeader(std::istream &stream) const;

    PbmDimensions readPbmDimensions(std::istream &stream) const;

    PbmDimensions pbmDimensions;

public:
    using ColumnDimensionType = PbmImage::vectorColumnType::size_type;
    using RowDimensionType = PbmImage::vectorRowType::size_type;

    void load(const std::string &path);

    ColumnDimensionType getFirstDimensions() const;

    RowDimensionType getSecondDimension() const;

    void setBit(ColumnDimensionType i, RowDimensionType j, Bit bit);

    Bit getBit(ColumnDimensionType i, RowDimensionType j) const;

    void save(const std::string &path);

    void printBits();

    void seedFill4(ColumnDimensionType i, RowDimensionType j, Bit bit);
};


#endif //PRC_PBMIMAGE_H
