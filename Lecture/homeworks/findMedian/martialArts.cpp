#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class MartialArtsCompare {
private:
    static std::vector<int> const levelList;
    static std::vector<std::string> const nameList;
    static int idx_of (std::string name) {
        for (int i = 0; i < nameList.size(); i++) 
            if (name == nameList[i])
                return i;
        return -1;
    }
public:
    static bool is_table_correct() {return levelList.size()==nameList.size();}
    static int level_of(std::string name) {
        int idx = idx_of(name);
        return (idx!=-1) ? levelList[idx] : -1;
    }
    static bool lt (std::string nm1, std::string nm2) {
        return level_of(nm1) > level_of(nm2);
    }
    static bool gt (std::string nm1, std::string nm2) {
        return level_of(nm1) < level_of(nm2);
    }
    static bool eq (std::string nm1, std::string nm2) {
        return level_of(nm1) == level_of(nm2);
    }
    static bool neq (std::string nm1, std::string nm2) {
        return !eq(nm1, nm2);
    }
    static bool nlt (std::string nm1, std::string nm2) {
        return !lt(nm1, nm2);
    }
    static bool ngt (std::string nm1, std::string nm2) {
        return !gt(nm1, nm2);
    }
};

std::vector<int> const MartialArtsCompare::levelList = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 9, 9, 9, 10, 10};

std::vector<std::string> const MartialArtsCompare::nameList = {"HuangShang", "XiaoYaoZi", "DaMoLaoZu", "SaoDiSeng" ,"ZhangSanFeng", "DuGuQiuBai", "JueYuan", "WuYaZi", "WangChongYang", "DuanYu", "XuZhu", "QiaoFeng", "LaoWanTong", "HongQiGong", "HuangYaoShi", "OuYangFeng", "DuanHuangYe", "GuoJing", "YangGuo", "XiaoLongNv", "ZhangWuJi", "JinLunFaWang", "FengQingYang", "FangZhengDaShi", "LingHuChong", "DongFangBuBai", "RenWoXing", "ChongXuDaoZhang", "XieXun", "ZhangCuiShan", "ZuoLengChan", "TaoGuLiuXian", "BuJieHeShang"};

template <typename vector_T>
void disp(std::vector<vector_T> vec) {
    vector_T last = *(vec.end()-1);
    for (auto elem: vec)
        std::cout << elem << ( (elem==last) ? "\n" : " ");
}

template <typename T, typename Cmp>
void quick_sort(std::vector<T> & arr, int lo, int hi) {
    // in ascendence
    // require lo < hi
    T piv = arr[hi]; int k = lo - 1;
    for (int i = lo; i < hi; i++)
        if (Cmp::lt(arr[i], piv))
            // i is current elem, k is ordered-part suffix
            swap(arr[i], arr[++k]);
    swap(arr[hi], arr[++k]); // as before, k is suffix so ++k is position of piv
    if (lo < k - 1) quick_sort<T, Cmp>(arr, lo, k - 1);
    if (k + 1 < hi) quick_sort<T, Cmp>(arr, k + 1, hi);
}

void quick_sort_martialArts (std::vector<std::string> & names) {
    // In ascendance order.
    quick_sort<std::string, MartialArtsCompare>(names, 0, names.size()-1);
}

template<typename T, typename Cmp>
void merge(std::vector<T> & arr, int lo, int hi) {
    int mid = lo + hi >> 1; // [lo, mid], [mid+1, hi]
    std::vector<T> left, right;
    int lenl = mid - lo + 1, lenr = hi - mid;
    left.assign(arr.begin()+lo, arr.begin()+mid+1);
    right.assign(arr.begin()+mid+1, arr.end());
    for(int i = lo, j = 0, k = 0; (j < lenl) || (k < lenr); ) {
        // have to be ngt when looking at left part to make it stable
        if ( (j < lenl) && (!(k < lenr) || Cmp::ngt(left[j], right[k])) ) 
            arr[i++] = left[j++];
        if ( (k < lenr) && (!(j < lenl) || Cmp::lt(right[k], left[j])) ) 
            arr[i++] = right[k++];
    }
    std::vector<T>().swap(left); std::vector<T>().swap(right);
}

template <typename T, typename Cmp>
void merge_sort(std::vector<T> & arr, int lo, int hi) {
    if (hi - lo <= 1) return ;
    int mid = (lo + hi) >> 1;
    merge_sort<T, Cmp>(arr, lo, mid); // [lo, mid]
    merge_sort<T, Cmp>(arr, mid+1, hi); // [mid+1, hi]
    merge<T, Cmp>(arr, lo, hi);
}

void merge_sort_martialArts (std::vector<std::string> & names) {
    // In ascendance order.
    merge_sort<std::string, MartialArtsCompare>(names, 0, names.size()-1);
}

int main() {

    /* test utils */
    // disp<std::string>(names);
    // std::cout << MartialArtsCompare::is_table_correct() << std::endl;
    std::cout << MartialArtsCompare::lt("HuangShang", "XieXun") << std::endl;
    std::cout << MartialArtsCompare::eq("HuangShang", "XiaoYaoZi") << std::endl;
    std::cout << MartialArtsCompare::lt("XieXun", "HuangShang") << std::endl;

    /* test sorts*/
    std::vector<std::string> names1 = {"HuangShang" , "ZhangWuJi", "HongQiGong", "HuangYaoShi", "SaoDiSeng", "WuYaZi", "GuoJing", "YangGuo", "RenWoXing", "FengQingYang", "XieXun", "LingHuChong", "FangZhengDaShi", "DuGuQiuBai", "DuanYu", "QiaoFeng"};
    std::vector<std::string> names2; names2.assign(names1.begin(), names1.end());

    // sort(names1.begin(), names1.end(), MartialArtsCompare::lt); disp<std::string>(names1);
    quick_sort_martialArts(names1); disp<std::string>(names1);
    stable_sort(names2.begin(), names2.end(), MartialArtsCompare::lt); disp<std::string>(names2);
    merge_sort_martialArts(names2); disp<std::string>(names2);

    return 0;
}