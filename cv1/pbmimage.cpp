#include <fstream>
#include <iostream>
#include "pbmimage.h"

void PbmImage::load(const std::string &path) {
    std::fstream pbmFile;
    pbmFile.open(path);
    if (pbmFile) {
        if (readPbmHeader(pbmFile)) {
            pbmDimensions = readPbmDimensions(pbmFile);

            for (PbmDimensions::second_type rowIndex = 0; rowIndex < pbmDimensions.second; rowIndex++) {
                // new vector for each row
                pbmBits.push_back(vectorRowType());
                for (PbmDimensions::first_type columnIndex = 0; columnIndex < pbmDimensions.first; columnIndex++) {
                    bool bit;
                    pbmFile >> bit;
                    pbmBits[rowIndex].push_back(bit);
                }
            }
            pbmFile.close();
        } else {
            // error
        }
    } else {
        // error
    }
}


void PbmImage::save(const std::string &path) {
    std::fstream pbmFile;
    pbmFile.open(path, std::fstream::out);
    if (pbmFile) {
        pbmFile << "P1" << std::endl;
        pbmFile << pbmDimensions.first << " " << pbmDimensions.second << std::endl;

        for (PbmDimensions::second_type rowIndex = 0; rowIndex < pbmDimensions.second; rowIndex++) {
            for (PbmDimensions::first_type columnIndex = 0; columnIndex < pbmDimensions.first; columnIndex++) {
                pbmFile << pbmBits[rowIndex][columnIndex] << " ";
            }
            pbmFile << std::endl;
        }
        pbmFile.close();
    } else {
        // error
    }
}

bool PbmImage::readPbmHeader(std::istream &stream) const {
    std::string header;
    stream >> header;

    return (header == "P1");
}

PbmImage::PbmDimensions PbmImage::readPbmDimensions(std::istream &stream) const {
    PbmDimensions dimensions;
    stream >> dimensions.first >> dimensions.second;
    return dimensions;
}

PbmImage::ColumnDimensionType PbmImage::getFirstDimensions() const {
    return pbmBits.size();
}

PbmImage::RowDimensionType PbmImage::getSecondDimension() const {
    if (pbmBits.empty()) {
        return 0;
    } else {
        return pbmBits.front().size();
    }
}

void PbmImage::setBit(PbmImage::ColumnDimensionType i, PbmImage::RowDimensionType j, Bit bit) {
    if (i <= getFirstDimensions() && j <= getSecondDimension()) {
        pbmBits[i][j] = bit;
    } else {
        // error
    }
}

PbmImage::Bit PbmImage::getBit(PbmImage::ColumnDimensionType i, PbmImage::RowDimensionType j) const {
    return pbmBits[i][j];
    // throws exception if out of range
}

void PbmImage::printBits() {
    for (PbmDimensions::second_type rowIndex = 0; rowIndex < pbmDimensions.second; rowIndex++) {

        for (PbmDimensions::first_type columnIndex = 0; columnIndex < pbmDimensions.first; columnIndex++) {
            std::cout << pbmBits[rowIndex][columnIndex] << " ";
        }
        std::cout << std::endl;
    }

}


void PbmImage::seedFill4( PbmImage::RowDimensionType i, PbmImage::ColumnDimensionType j, Bit bit) {
    if (i < 0 || j < 0 || i >= pbmDimensions.second || j >= pbmDimensions.first) return;
    Bit bitToBeChanged = pbmBits[i][j];
    if (bitToBeChanged == bit) return;
    pbmBits[i][j] = bit;
    seedFill4(i + 1, j, bit);
    seedFill4(i - 1, j, bit);
    seedFill4(i, j + 1, bit);
    seedFill4(i, j - 1, bit);
}

