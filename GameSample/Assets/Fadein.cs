using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Fadein : MonoBehaviour
{
    GameObject PanelObject;
    float Alpha;
    Image FadeColor;
    Color c = Color.black;
    bool isFadeIn = true;
    bool isFadeOut = false;

    // Start is called before the first frame update
    void Start()
    {
        Alpha = 1;
        this.PanelObject = GameObject.Find("Panel");

        FadeColor = this.PanelObject.GetComponent<Image>();
    }

    private void FixedUpdate()
    {
        if (isFadeIn)
        {
            Alpha -= 0.03125f;

            c.a = Alpha;
            FadeColor.color = c;

            if (Alpha < 0)
            {
                isFadeIn = false;

                this.gameObject.SetActive(false);
            }
        }
        if (isFadeOut)
        {
            Alpha += 0.03125f;

            c.a = Alpha;
            FadeColor.color = c;
        }


    }

    public void IsFadeOut()
    {
        isFadeOut = true;
    }
}
