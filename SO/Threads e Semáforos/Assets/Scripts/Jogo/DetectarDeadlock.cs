using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DetectarDeadlock : MonoBehaviour
{
    [SerializeField] private GameObject _mensagem;

    private List<Image> _barrasProgressao;

    // Start is called before the first frame update
    void Start()
    {
        //Encontra o controlador de recursos do jogo
        GameObject[] threads = GameObject.FindGameObjectsWithTag("Thread");

        _barrasProgressao = new List<Image>();
        //Para cada controlador de imagem dos objetos-filhos
        foreach(GameObject thread in threads)
        {
            foreach (var item in thread.GetComponentsInChildren<Image>())
            {
                //Se for do tipo filled
                if (item.type == Image.Type.Filled)
                {
                    //Salva o controlador, pois pertence à barra de progresso
                    _barrasProgressao.Add(item);
                    break;
                }
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        int contTravados = 0;

        foreach(Image item in _barrasProgressao)
        {
            if(item.color == Color.red)
            {
                contTravados++;
            }
        }

        if(contTravados == _barrasProgressao.Count)
        {
            _mensagem.SetActive(true);
            Destroy(this);
        }
    }
}
