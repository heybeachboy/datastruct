//
// Created by DELL on 2019/4/14.
//

#ifndef DATASTRUCT_MATRIX_H
#define DATASTRUCT_MATRIX_H
#define MARTRIX_W 10 //二维矩阵的宽度
#define MARTRIX_H 10 //二维矩阵的高度
#define EMPTY 0  //表示位置为空
#define PRODUTCT 1 //表示位置产品经理
#define DEVELOPER 2 //表示位置为开发者
class Martix {
      public:
      /**
       * 判断矩阵的产品经理是不是可以全部转换为开发人员
       * @param martrix
       * @return
       */
       int IsChangeToDeveloper(int martrix[MARTRIX_H][MARTRIX_W]){
           int count = 0;
           for(int i = 0;i< MARTRIX_H ; i++) {
              for(int j=0; j< MARTRIX_W;j++) {
                  int val = martrix[i][j];
                  if(val == PRODUTCT ) {
                     if(!SearchBackgroundDeveloper(martrix,i,j)) {
                         return -1;
                     }else{
                         count++;
                     }
                  }
              }
           }

           return count;

      };
      private:
      /**
       * 从产品经理有位置从左上右下的方向依次寻找最近和开发都，看是不是符合转换有条件
       * @param martrix
       * @param i
       * @param j
       * @return
       */
       bool SearchBackgroundDeveloper(int martrix[MARTRIX_H][MARTRIX_W],int i,int j) {
            //从产品经理的位置向左边寻找最近的开发

            //从产品经理的位置向上方向寻找最近和开发

           //从产品经理的位置向右方向寻找最近和开发

           //从产品经理的位置向下方向寻找最近和开发
           return true;
       }



};

#endif //DATASTRUCT_MATRIX_H
