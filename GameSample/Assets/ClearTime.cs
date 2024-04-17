using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ClearTime : MonoBehaviour
{
    public GameObject score_object = null;
    public static int score_num = 0;//スコア変数
    public static int score_count = 0;
    int BonusTime;
    int count;
    public AudioClip se;
    // Start is called before the first frame update
    void Start()
    {
        BonusTime = Timer.TimeCount;
    }

    private void Update()
    {
        // オブジェクトからTextコンポーネントを取得
        Text score_text = score_object.GetComponent<Text>();

        // テキストの表示を入れ替える
        score_text.text = "" + BonusTime;
    }
    // Update is called once per frame
    void FixedUpdate()
    {
        count++;
        if (count > 50)
        {
            if (BonusTime > 0)
            {
                BonusTime--;
                AudioSource.PlayClipAtPoint(se, transform.position);
                ClearScore.score_num += 200;
            }
        }
    }
}
