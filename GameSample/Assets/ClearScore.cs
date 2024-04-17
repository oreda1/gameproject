using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ClearScore : MonoBehaviour
{
    public GameObject score_object = null;
    public static int score_num = 0;//スコア変数
    public static int score_count = 0;
    void Start()
    {
        score_num = ScoreManager.score_num;
        ScoreManager.score_num = 0;
    }


    void Update()
    {
        // オブジェクトからTextコンポーネントを取得
        Text score_text = score_object.GetComponent<Text>();
        // テキストの表示を入れ替える
        score_text.text = "" + score_num;

    }
}