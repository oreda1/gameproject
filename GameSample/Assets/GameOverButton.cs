using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOverButton : MonoBehaviour
{
    public AudioClip se;
    GameObject Fade;
    bool isFlag;
    int count;
    // Start is called before the first frame update
    void Start()
    {
        count = 0;
        Fade = GameObject.Find("Panel");
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (isFlag)
        {
            count++;
        }
        if (count > 50)
        {
            SceneManager.LoadScene("TitleScene");
        }
    }
    public void ClickStartButton()
    {
        isFlag = true;
        Fade.SetActive(true);
        Fade.GetComponent<Fadein>().IsFadeOut();
        AudioSource.PlayClipAtPoint(se, transform.position);
    }
}
