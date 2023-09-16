import axios from 'axios';

const fetchNewsHelper = async ()=>{
    try {
        const res=await axios.get(`/news`);
        return res.data;
    } catch (error) {
        console.log(error);
    }
}

const feactNewsByIdHelper=async (id)=>{
    try {
        const res=await axios.get(`/news/${id}`);
        return res.data;
    } catch (error) {
        console.log(error);
    }
}

export const fetchNews=()=>{
    return {
        type:'fetch_news',
        payload:fetchNewsHelper()
    };
};

export const feactNewsById=(id)=>{
    return {
        type:'fetch_news_by_id',
        payload:feactNewsByIdHelper(id)
    };
};
