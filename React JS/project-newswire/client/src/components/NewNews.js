import React from 'react';
import { useFormik } from 'formik';
import * as Yup from 'yup';
import Alert from 'react-bootstrap/Alert';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';
import { toast } from 'react-toastify';
import { sendToast } from "../utils/sendToast";

const NewNews=()=>{
    const navigate=useNavigate();

    const addNewsToDB=async (values)=>{
        try {
            const news={
                title:values.title,
                image:values.image,
                author:values.author,
                content:values.content
            }
            await axios.post(`${}/news`,{news});
            sendToast('success','successfully posted the news');
            navigate('/');
        } catch (error) {
            sendToast('error','something went wrong');
            console.log(error);
        }
    };          

    const formik=useFormik({
        initialValues:{
            title:'',
            image:'',
            author:'',
            content:''
        },
        validationSchema:Yup.object({
            title:Yup.string().max(15,'Must be 15 character or less').required('Headline is required'),
            content:Yup.string().required('news body is required'),
            author:Yup.string().max(15,'Username must be below 15 character').required('Username is required'),
            content:Yup.string().url('must be a valid url').required('image is required')
        }),
        onsubmit:async(values)=>{
            await addNewsToDB(values);
        }

    });

        return (
            <div className='row' >  
            <div className='col-lg-6 mx-auto' >
                <form onSubmit={formik.handleSubmit} >
                    <div className='mb-4' >
                        <label className='from-label' htmlFor='title' >Title</label>
                        <input className='from-control' id='title' type='text' {...formik.getFieldProps('title')}/>
                        {
                            formik.touched.title && formik.errors.title?(
                                        <Alert className="mt-3" variant="danger" >{formik.errors.title}</Alert>
                            ):null
                        }

                    </div>
                    <div className='mb-4' >
                        <label className='from-label' htmlFor='content'>Content</label> 
                        <input className='from-control' id='content' type='text' {...formik.getFieldProps('content')}/>
                        {formik.touched.content && formik.errors.content ?(
                            <Alert className='mt-3' variant='danger' >{formik.errors.content}</Alert>
                        ):null}
                    </div>
                    <div className='mt-4'>
                        <label className='form-label' htmlFor='author' >Author</label>
                        <input className='from-control' id='author' type='text' {...formik.getFieldProps('author')}/>
                        {formik.touched.author && formik.errors.author ?(
                            <Alert className='mt-3' variant='danger' >{formik.errors.author}</Alert>
                        ):null}
                    </div>
                    <div className='mt-4' >
                        <label className='form-label' htmlFor='image' >Image</label>
                        <input className='from-control' id='image' type='text' {...formik.getFieldProps('image')}/>
                        {formik.touched.image && formik.errors.image?(
                            <Alert className="mt-3" variant="danger" >{formik.errors.image}</Alert>
                        ):null}
                    </div>
                    <button type='btn btn-primary' type='submit' >Submit</button>
                </form>
            </div></div>
        );
};

export default NewNews;