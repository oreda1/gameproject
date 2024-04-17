using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreManager : MonoBehaviour
{


    public GameObject score_object = null;
    public static int score_num;//スコア変数
    public static int score_count;
    void Start()
    {
        score_num = 0;
        score_count = 0;

    }


    void Update()
    {
        // オブジェクトからTextコンポーネントを取得
        Text score_text = score_object.GetComponent<Text>();
        // テキストの表示を入れ替える
        score_text.text = "Score" + score_num;
    }
}