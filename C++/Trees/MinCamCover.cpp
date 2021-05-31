#include<iostream>
#include<vector>
#include "../Utils/IOUtils.cpp"

using namespace std;

class MinCamerasCoverHelper{

public:
    int nCams;
    int minCameraCover(TreeNode * root) {
      nCams = 0;
      int nodesIdentifier = _minCameraCover(root);
      nCams = (nodesIdentifier == 2) ? nCams + 1 : nCams;
      return nCams;
    }
    int _minCameraCover(TreeNode * root) {
      if (root == NULL) return 1;
      int lCamCover = _minCameraCover(root -> left);
      int rCamCover = _minCameraCover(root -> right);
      if (lCamCover == 1 && rCamCover == 1) return 2;
      if (lCamCover == 2 || rCamCover == 2) {
        nCams++;
        return 3;
      }
      return 1;
    }
};

int main(){

	ioutils::enableFastIO();
	MinCamerasCoverHelper* minCamCov = new MinCamerasCoverHelper();

	return 0;
}