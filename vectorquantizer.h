#ifndef VECTORQUANTIZER_H
#define VECTORQUANTIZER_H

#include <fstream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class VectorQuantizer
{
public:
  // construtores
  VectorQuantizer();
  
  // Treinamento
  vector<Mat> Train(vector<string> imagens, string dim, int codeBookSize);
  vector<Mat> MakeCodebook(vector<Mat> vectorBucket, int codeBookSize); // OK !!!!!
  vector<Mat> Vectorize(vector<Mat> images, Point vectorSizes); // OK !!!!!
  vector<Mat> Vectorize(Mat imagem, Point vectorSizes); // OK !!!!!
  vector<vector<Mat>> FillBuckets(vector<Mat> vectorBucket, vector<Mat> codebook);
  vector<Mat> CalcAverageOfBucket(vector<vector<Mat>> codebookBuckets, Point vectorSizes);
  bool CheckCodebookChanges(vector<Mat> codebook, vector<Mat> newCodebook);
  void CompareVectorOfMat(vector<Mat> codebook1, vector<Mat> codebook2);
  
  // Quantização
  string Quantize(vector<Mat> codebook, string imageFile, string dim, int codeBookSize);
  
  // tools
  static Point Str2Dim(string dim);
  static void ShowVectorOfMat(vector<Mat> codebook);
  static void SaveCodebook(vector<Mat> codebook, string dimensoes, int codebookSize);
  static vector<Mat> loadCodebook(string codebookfile, string dimensoes, int codebookSize);
  static double Mse(Mat image1, Mat image2);
  vector<Mat> OpenImages(vector<string> imagesList);  
};

#endif // VECTORQUANTIZER_H
