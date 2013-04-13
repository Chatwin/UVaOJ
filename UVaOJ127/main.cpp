#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
//CARD�ṹ�壬�洢һ���ƣ�Face[0]��ʾ��ɫ��Face[1]��ʾ����
struct CARD {char Face[2];} Src;
//�Ƚ��������Ƿ�ƥ�䡣��ɫ�������ͬ��ƥ��
inline bool Match(const CARD &c1, const CARD &c2) {
    return (c1.Face[0] == c2.Face[0] || c1.Face[1] == c2.Face[1]);
}
int main(void) { //������
    typedef vector<CARD> PILE;
    char Pack[256]; //���ڴ洢�����һ���ƣ�����ѭ����ȡ���������
    for (string Line; getline(cin, Line) && Line[0] != '#'; cout << endl) {
        strcpy(Pack, Line.c_str()); //��ȡ���������������
        while (getline(cin, Line) && Line.empty()); //��ȡ��2��
        strcat(Pack, Line.c_str());
        *remove(&Pack[0], &Pack[strlen(Pack)], ' ') = '\0'; //ɾ�����еĿո�
        vector<PILE> Piles;
        for (int i = 0; i < 52; ++i) { //ѭ������ÿһ����
            PILE Stack(1, ((CARD*)&Pack)[i]);
            Piles.push_back(Stack); //���·����Ʒ������һ��
            //j��ʾ��ǰ�Ƶ�λ�ã�k��ʾj�����֮ƥ����Ƶ�λ��
            for (size_t j = Piles.size() - 1, k; j < Piles.size(); ++j) {
                //����ѭ��������ҿ����Ƶ�������ߵ�λ��
                for (k = j, Src = Piles[j].back(); k > 0; --k) {
                    if (k >= 3) { //���ж�����Ƿ���ڵ�3��
                        if (Match(Src, Piles[k - 3].back())) {
                            //�������ߵ�3��ƥ�䣬��kָ��������
                            k -= 2;
                            continue;
                        } //�����Ƶ�kָ���λ�ã������������
                    }
                    if (!Match(Src, Piles[k - 1].back())) {
                        break; //�����ߵ�3�ź͵�1�Ŷ�ʧ�䣬����ѭ��
                    }
                }
                if (k != j) { //k��ԭλ��j����ȱ�ʾ�����ƶ�
                    Piles[k].push_back(Piles[j].back()); //�ƶ���
                    Piles[j].pop_back();
                    if (Piles[j].empty()) { //����Ƶ����ƿ���ɾ��֮
                        Piles.erase(Piles.begin() + j);
                    }
                    j = k; //���ƶ��Ʋ��ҵ���㶨Ϊk
                }
            }
        } //���°�Ҫ��ĸ�ʽ��������ע�⵽Pile�е�����������
        int nSize = Piles.size();
        cout << nSize << " pile" << (nSize > 1 ? "s " : " ") << "remaining:";
        for (int i = 0; i < nSize; cout << ' ' << Piles[i++].size());
    }
    return 0;
}
