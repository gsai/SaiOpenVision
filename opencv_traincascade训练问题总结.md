#1 Train dataset for temp stage can not be filled. Branch training terminated#

出错原因：negtive_images数量为3000个，positive_images 数量为1184个，相差太大
解决办法： **reduce the number of negatives to the same number of positives**  (保持 negatives 数量和 positives 数量 相等），减少
           negatives 数量 或者增加 positives 数量 ）
           
           
#2 参数的意义及相关约束#
